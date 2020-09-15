#include "../lib/ReceiveData.h"
#include <fstream>
#include <sstream>

using namespace Receiver::ReceiverLib;

int main()
{
	const std::ifstream fileContent("results.txt"); //reading from file as of now to verify receiver same as reading from a stream

	std::stringstream stringStream;
	stringStream << fileContent.rdbuf();
	std::string received_Data = stringStream.str();

	ReceiveData receiver;
	receiver.start(received_Data);	 
}