#include "ConsoleOutput.h"
#include <iostream>
#include <vector>
#include <string>

bool checkHeaderListSize(std::string& output) {
	if (headerList.size() == 0) {
		output = "";
		return true;
	}
	else if (headerList.size() == 1) {
		output = headerList[0];
		return true;
	}
	return false;
}

std::string headerListToString() {
	
	std::string output = "";

	if (checkHeaderListSize(output)) {
		return output;
	}

	size_t i;
	for (i = 0; i < headerList.size()-1; i++) {
		output += headerList[i] + ',';
	}
	output += headerList[i];
	return output;
}

void printColumn(std::vector<std::string> columnData) {
	for (auto itrvec : columnData) {
		std::cout << itrvec << std::endl;
	}
}

bool ConsoleOutput::write() {

	std::string headers="";
	headers = headerListToString();
	
	std::cout << headers << std::endl;
	
	size_t i;
	for (i = 0; i < headerList.size(); i++) {
		printColumn(parsedCsvFile[headerList[i]]);

		if( i < headerList.size() -1)
			std::cout << "+-+" << std::endl;
	}

	return true;
}
