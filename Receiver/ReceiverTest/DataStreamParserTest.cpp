//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "../lib/DataStreamParser.h"

using namespace Receiver::ReceiverLib;

TEST_CASE("updateColumnLabels when data from the stream is empty")
{
	DataStreamParser data_stream_parser;
	std::string data {};
	
	REQUIRE(data_stream_parser.updateColumnLabels(data) == -1);
}

TEST_CASE("updateColumnLabels when data from the stream is non-empty")
{
	DataStreamParser data_stream_parser;
	std::string data{"stream content"};

	REQUIRE(data_stream_parser.updateColumnLabels(data) == 0);
}

TEST_CASE("handleParsedData when stream is empty with no column contents then columnData left as it is")
{
	DataStreamParser data_stream_parser;
	std::string data{};
	std::string label{ "reviews,dates" };
	data_stream_parser.updateColumnLabels(label);

	data_stream_parser.handleParsedData(data);
	auto result = data_stream_parser.getColumns();

	for (auto& column : result)
	{
		REQUIRE(column._columnData.empty());
	}
}

TEST_CASE("handleParsedData when stream is non-empty with column contents then updates columndata with parsed content")
{
	DataStreamParser data_stream_parser;
	std::string data{"this is first comment\nthis is second comment\n+-+\n13-02-2020"};
	std::string label{ "reviews,dates" };
	
	data_stream_parser.updateColumnLabels(label);
	data_stream_parser.handleParsedData(data);
	auto result = data_stream_parser.getColumns();

	for(auto& column: result)
	{
		REQUIRE(!column._columnData.empty());
	}
}

