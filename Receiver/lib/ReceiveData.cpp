#include "ReceiveData.h"
#include "DataStreamParser.h"
#include "WordFrequencyCounter.h"
#include <iostream>

namespace Receiver
{
	namespace ReceiverLib
	{
		void ReceiveData::start(std::string& data)
		{
			DataStreamParser data_stream_parser(data);
			data_stream_parser.updateColumnLabels(data);
			data_stream_parser.handleParsedData(data);
			WordFrequencyCounter word(data_stream_parser);
			word.transformColumnData();
			word.wordFrequency();
			word.outputWordCountResult();
		}

		std::string ReceiveData::acceptInput()
		{
			std::string content, word;
			while (std::getline(std::cin, word))
			{
				if (!word.empty())
				{
					if (word == "-+-")
						break;
					content.append(word).append("\n");
 				}
			}
			return content;
		}
	}
}
 