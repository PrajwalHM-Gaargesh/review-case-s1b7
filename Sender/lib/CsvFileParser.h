#pragma once

#include "IFileParser.h"
#include "GlobalVars.h"

#include <fstream>
#include <iostream>
#include <map>
#include <vector>



class CsvFileParser : public IFileParser {
public:
	void parseHeader(std::fstream&);
	void parseRow(std::fstream&);
};