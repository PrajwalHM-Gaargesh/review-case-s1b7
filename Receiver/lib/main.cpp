#include "ReceiveData.h"
#include <sstream>

using namespace Receiver::ReceiverLib;

int main()
{
	ReceiveData receiver;
	auto content = receiver.acceptInput();
	receiver.start(content);
}