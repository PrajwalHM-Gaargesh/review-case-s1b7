//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include<iostream>
#include<fstream>

#include "../lib/CsvFileParser.cpp"
#include "../lib/GlobalVars.h"


TEST_CASE("When header row is parsed and header row is empty, Then raise error") {
	CsvFileParser csvfp;
	std::fstream dummyFile("dummy.csv");
	csvfp.parseHeader(dummyFile);
	REQUIRE((headerList.size()) == 2);
}

TEST_CASE("When parsed row contains empty rows, then ignore the row") {
	CsvFileParser csvfp;
	std::fstream dummyFile("dummy.csv");			//12 total rows, 7 non empty rows
	csvfp.parseHeader(dummyFile);
	csvfp.parseRow(dummyFile);
	auto itr = parsedCsvFile.begin();
	REQUIRE((itr->second).size() == 7);
}