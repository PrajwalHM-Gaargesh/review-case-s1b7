#include "CsvFileParser.h"
#include <sstream>
#include <iostream>

CsvFileParser::CsvFileParser(){
	parsedCsvFile.clear();
	headerList.clear();
}

void fillMap(std::string rows) {

	if (rows.size() <= 2) {
		return;
	}

	int colPos = 0;
	std::string rowToken;

	std::stringstream ss(rows);
	while (std::getline(ss, rowToken, ',')) {
		//std::cout << "CsvParser rowToken:" << rowToken << std::endl;
		parsedCsvFile[headerList[colPos]].push_back(rowToken);
		colPos++;
	}
	if (rows[rows.size() - 1] == ',') {
		parsedCsvFile[headerList[colPos]].push_back("");
	}

}

void CsvFileParser::parseHeader(std::fstream& csvFile) {
	std::string header;
	getline(csvFile, header);
	
	std::stringstream ss(header);
	std::string headerToken;
	char delim = ',';
	while (std::getline(ss, headerToken, delim)) {
		headerList.push_back(headerToken);
	}
	
}

void CsvFileParser::parseRow(std::fstream& csvFile) {

	std::string rows;

	while (getline(csvFile, rows)) {
				
		//fill in the map
		fillMap(rows);
		
	}

}
