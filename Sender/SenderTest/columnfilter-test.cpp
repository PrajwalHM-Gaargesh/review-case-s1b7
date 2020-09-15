//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "../lib/ColumnFilter.cpp"
#include "../lib/GlobalVars.h"
#include <vector>
#include <string>

TEST_CASE("When no column filter provided, Then data from all columns analyzed") {
	std::vector<std::string> argList={"file.cpp","file.csv"};
	ColumnFilter* cfilter = new ColumnFilter(argList);
	REQUIRE((cfilter->filterColumns()) == true);
}

TEST_CASE("When a valid colun filter is provided, Then only analyze data from that column") {
	std::vector<std::string> argList={"file.cpp","file.csv","column1"};
	headerList = {"column1","column2"};
	ColumnFilter* cfilter = new ColumnFilter(argList);
	REQUIRE((cfilter->filterColumns()) == true);
	
	headerList = {"column1","column2"};
	argList={"file.cpp","file.csv","column1","column2"};
	ColumnFilter* cfilter1 = new ColumnFilter(argList);
	REQUIRE((cfilter1->filterColumns()) == true);
	
}

TEST_CASE("When invalid column header is provided, Then throw error") {
	std::vector<std::string> argList={"file.cpp","file.csv","colmn1"};
	ColumnFilter* cfilter = new ColumnFilter(argList);
	headerList = {"column1","column2"};
	REQUIRE((cfilter->filterColumns()) == false);
	std::cout<<headerList.size()<<std::endl;
	
	argList = {"file.cpp","file.csv","column1","colum"};
	ColumnFilter* cfilter1 = new ColumnFilter(argList);
	REQUIRE((cfilter1->filterColumns()) == false);
	
	argList = {"file.cpp","file.csv","column1","colum2","more","columns"};
	ColumnFilter* cfilter2 = new ColumnFilter(argList);
	REQUIRE((cfilter2->filterColumns()) == false);
}