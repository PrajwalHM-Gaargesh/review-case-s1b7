#pragma once

#include "DataStreamParser.h"

namespace Receiver
{
	namespace ReceiverLib
	{
		struct WordCountResult
		{
		 	std::string _word;
			std::string _columnLabel;
			size_t _countValue;
		};
		
		class WordFrequencyCounter
		{
		private:
			std::vector<WordCountResult> wordCount;
			DataStreamParser _dataStreamParser;

		public:
			WordFrequencyCounter() = default;
			explicit WordFrequencyCounter(DataStreamParser& data_stream_parser) : _dataStreamParser(data_stream_parser) {}
			void wordFrequency();
			void transformColumnData();
			void outputWordCountResult();
			std::vector<WordCountResult> getWordCount();
		};
	}
}
