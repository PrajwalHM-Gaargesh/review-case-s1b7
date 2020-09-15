#include "DataStreamParser.h"

namespace Receiver
{
	namespace ReceiverLib
	{
		void DataStreamParser::handleParsedData(std::string& data)
		{
			std::stringstream streamContent;
			streamContent << data;
			for(auto& column : _columns)
			{
				splitColumnData(streamContent, column);
			}
		}

		void splitColumnData(std::stringstream& data, Column& column)
		{
			std::string line;
			std::stringstream lineContent;
			while (std::getline(data, line))
			{
				if (line.find(',') != std::string::npos)   //ignore first line of stream having column labels
					continue;
				if (line == "+-+")   //delimiter for different column contents
					break;
				lineContent.str(line);
				checkForDelimiter(lineContent, column);
				lineContent.clear();
			}
		}

		void checkForDelimiter(std::stringstream& lineContent, Column& column)
		{
			std::string word;
			while (std::getline(lineContent, word, ' '))
			{
				column._columnData.push_back(word);
			}
		}

		std::vector<Column>& DataStreamParser::getColumns()
		{
			return _columns;
		}

		int DataStreamParser::updateColumnLabels(std::string& data)
		{
			std::string word,line;
			std::stringstream streamContent,lineContent;
			Column col;
			streamContent << data;

			std::getline(streamContent, line);
 			lineContent.str(line);
			while (std::getline(lineContent, word, ','))
			{
				col._columnLabel = word;
				_columns.push_back(col);
			}
			lineContent.clear();

			if(_columns.empty())
				return -1;
			return 0;
		}
	}
}
