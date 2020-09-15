#include "Sender.h"
#include "GlobalVars.h"

#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <memory>

std::vector<std::string> headerList;
std::map<std::string, std::vector<std::string>> parsedCsvFile;
std::fstream csvFile;



bool validInputFile(std::string path, std::fstream& csvFile) {

	csvFile.open(path);
	if (csvFile.is_open()) {
		//std::cout << "File is open" << std::endl;
	}
	else {
		//std::cout << "File is not open" << std::endl;
	}
	if (csvFile.fail()) {
		//std::cout << "Failed to open" << std::endl;
	}
	else {
		//std::cout << "File opened successfully" << std::endl;
		return true;
	}
	return false;
}

bool regexCheck(int argc, std::vector<std::string> argv, std::fstream& csvFile) {
	std::regex inputFileName("(.*)(\\.csv)");

	if (argc > 1) {
		std::string filePath = argv[1];
		//std::cout << "Path to file: " << filePath << std::endl;
		if (!(regex_match(filePath, inputFileName))) {
			//std::cout << "FileName Invalid" << std::endl;
			return false;
		}
		else {
			//std::cout << "Valid FileName: " << filePath << std::endl;
			if (validInputFile(filePath,csvFile)) { return true; }
		}
	}
	return false;
}

Sender::Sender(IFileParser* ifp, IOutput* iout, int argc, char* argv[]) {
	fileParser = ifp;
	output = iout;
	argCount = argc;
	for (int i = 0; i < argc; i++) {
		args.push_back(argv[i]);
	}
}

bool Sender::start() {

	if (!regexCheck(argCount, args, csvFile)) {
		return false;
	}

	ColumnFilter* filter = new ColumnFilter(args);
	std::unique_ptr<Validator> validate = std::make_unique<Validator>();

	fileParser->parseHeader(csvFile);
	validate.validateHeaders();

	fileParser->parseRow(csvFile);

	if (!filter->filterColumns()) {
		return false;
	}
	
	output->write();

	return true;
}
