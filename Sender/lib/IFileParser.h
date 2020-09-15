#pragma once
#include <fstream>
#include <string>

class IFileParser {
private:

public:
	virtual void parseHeader(std::fstream&) = 0;
	virtual void parseRow(std::fstream&) = 0;
};