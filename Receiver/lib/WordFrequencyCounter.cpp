#include "WordFrequencyCounter.h"
#include <algorithm>
#include <iostream>
#include <fstream>

namespace Receiver
{
	namespace ReceiverLib
	{
		void WordFrequencyCounter::outputWordCountResult()
		{
			std::ofstream file("FinalResult.csv");
			file << "Column" << "," << "Word" << "," << "WordFrequency" << std::endl;
			for(auto& word_count : wordCount)
			{
				std::cout << word_count._columnLabel << "Column : " << word_count._word << " : " << word_count._countValue << std::endl;
				file << word_count._columnLabel << "Column " << "," << word_count._word << "," << word_count._countValue << std::endl;
			}
		}

		std::vector<WordCountResult> WordFrequencyCounter::getWordCount()
		{
			return wordCount;
		}

		void WordFrequencyCounter::wordFrequency()
		{
			auto columns = _dataStreamParser.getColumns();
			std::vector<std::string> unique_words;

			for(auto& column : columns)
			{
				auto& columnData = column._columnData;
				auto column_iterator = columnData.begin();
				WordCountResult word_count_result;
				while (column_iterator != columnData.end())
				{
					word_count_result._columnLabel = column._columnLabel;
					if (std::find(unique_words.begin(), unique_words.end(), *column_iterator) == unique_words.end())
					{
						word_count_result._word = *column_iterator;
 						word_count_result._countValue = std::count(columnData.begin(), columnData.end(), *column_iterator);
						wordCount.push_back(word_count_result);
						unique_words.push_back(*column_iterator);
						++column_iterator;
					}
					else
					{
						++column_iterator;
					}
				}
			}
		}

		void WordFrequencyCounter::transformColumnData()
		{
			auto& columns = _dataStreamParser.getColumns();

			for (auto& column : columns)
			{
				for(auto& word : column._columnData)
				{
					std::transform(word.begin(), word.end(), word.begin(), ::tolower);
				}
			}
		}
	}
}
