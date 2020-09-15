#pragma once
#include "CsvFileParser.h"
#include "ConsoleOutput.h"
#include "ColumnFilter.h"
#include "Validator.h"
#include "GlobalVars.h"

class Sender {
private:
	IFileParser* fileParser;
	IOutput* output;
	int argCount;
	std::vector<std::string> args;
public:
	//Sender(IFileParser* ifp, IOutput* iout, int argc, std::vector<std::string> argv) :fileParser(ifp), output(iout), argCount(argc), args(argv) {}
	Sender(IFileParser* ifp, IOutput* iout, int argc, char* argv[]);
	bool start();
};