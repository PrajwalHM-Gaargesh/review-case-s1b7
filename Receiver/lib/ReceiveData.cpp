#include "ReceiveData.h"
#include "DataStreamParser.h"
#include "WordFrequencyCounter.h"

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
	}
}
 