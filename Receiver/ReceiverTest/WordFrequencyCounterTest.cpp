#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../lib/WordFrequencyCounter.cpp"
#include "catch.hpp"
#include <cctype>
#include <experimental/filesystem>

using namespace Receiver::ReceiverLib;

TEST_CASE("when data is sent via the stream then wordCount Result will be non-zero")
{
	//to fill columnData
	DataStreamParser data_stream_parser;
	std::string data{ "this is first comment\nthis is second comment\n+-+\n13-02-2020" };
	std::string label{ "reviews,dates" };

	data_stream_parser.updateColumnLabels(label);
	data_stream_parser.handleParsedData(data);

	WordFrequencyCounter word_frequency(data_stream_parser);
	word_frequency.wordFrequency();

	auto wordCountResults = word_frequency.getWordCount();
	REQUIRE(!wordCountResults.empty());
}

TEST_CASE("when no data is sent via the stream then wordCount Result will be zero")
{
	//initial setup
	DataStreamParser data_stream_parser;
	std::string data{};
	std::string label{ "reviews,dates" };

	data_stream_parser.updateColumnLabels(label);
	data_stream_parser.handleParsedData(data);

	WordFrequencyCounter word_frequency(data_stream_parser);
	word_frequency.wordFrequency();

	auto wordCountResults = word_frequency.getWordCount();
	REQUIRE(wordCountResults.empty());
}

TEST_CASE("transformColumnData when provided with non-empty stream converts the vector values to lower case")
{
	//to fill columnData
	DataStreamParser data_stream_parser;
	std::string data{ "THIS IS FIRST COMMENT\nTHIS IS SECOND COMMENT\n+-+\n" };
	std::string label{ "reviews,dates" };

	data_stream_parser.updateColumnLabels(label);
	data_stream_parser.handleParsedData(data);

	WordFrequencyCounter word_frequency(data_stream_parser);
	word_frequency.transformColumnData();
	word_frequency.wordFrequency();
	auto wordCountResults = word_frequency.getWordCount();

	for(auto& wordCount : wordCountResults)
	{
		for (auto char_element : wordCount._word)
		{
			REQUIRE(std::islower(char_element) != 0);
		}
	}
}

//TEST_CASE("outPutWordCountResult when called displays output result and writes same result to a csv file")
//{
//	//to fill columnData
//	DataStreamParser data_stream_parser;
//	std::string data{ "THIS IS FIRST COMMENT\nTHIS IS SECOND COMMENT\n+-+\n" };
//	std::string label{ "reviews,dates" };
//
//	data_stream_parser.updateColumnLabels(label);
//	data_stream_parser.handleParsedData(data);
//
//	WordFrequencyCounter word_frequency(data_stream_parser);
//	word_frequency.transformColumnData();
//	word_frequency.wordFrequency();
//	word_frequency.outputWordCountResult();
//
//	REQUIRE(std::experimental::filesystem::exists("FinalResult.csv"));
//}

