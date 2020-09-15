#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include "../lib/ConsoleOutput.cpp"
#include "../lib/GlobalVars.h"

#include <map>
#include <vector>
#include <string>


TEST_CASE("When a map<string,vector<string>> is passed to ConsoleOutput, then the contents are printed on console") {
	ConsoleOutput* co = new ConsoleOutput;
	std::map<std::string, std::vector<std::string>> dummyMap;
	dummyMap["column1"] = {"row1","row2"};
	dummyMap["column2"] = {"row1","row2"};
	parsedCsvFile = dummyMap;
	headerList.push_back("column1");
	headerList.push_back("column2");
	std::cout<<parsedCsvFile["column1"].size()<<std::endl;
	REQUIRE((co->write())==true);
}