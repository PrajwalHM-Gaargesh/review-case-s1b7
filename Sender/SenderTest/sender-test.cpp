//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include "../lib/Sender.cpp"
#include "../lib/Validator.cpp"
//#include "../lib/ColumnFilter.cpp"

class DummyOutput : public IOutput {
private:
	bool wr = false;
public:
	bool write() { wr = true; return true; }
};
class DummyParser : public IFileParser {
private:
	bool ph = false;
	bool pr = false;
public:
	DummyParser() { ph = false; pr = false; }
	void parseHeader(std::fstream& fs) { ph = true; }
	void parseRow(std::fstream& fs) { pr = true; }
};

TEST_CASE("When an invalid file extension is passed, then exit without proceeding") {
	std::fstream dummyStream;
	DummyParser* dp = new DummyParser;
	DummyOutput* dop = new DummyOutput;
	char* ar[] = {(char*)"Hello", (char*)"There"};
	Sender* send = new Sender(dp, dop, sizeof(ar)/sizeof(ar[0]), ar);
	
	REQUIRE( (send->start())== false);
}

TEST_CASE("When a valid file is passed, Then proceed with analysis") {
	std::fstream dummyStream;
	DummyParser* dp = new DummyParser;
	DummyOutput* dop = new DummyOutput;
	char* ar[] = {(char*)"Hello", (char*)"dummy.csv"};
	Sender* send = new Sender(dp, dop, 2, ar);
	REQUIRE((send->start())==true);
}