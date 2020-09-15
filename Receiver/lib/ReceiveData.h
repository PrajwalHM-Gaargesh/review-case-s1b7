#pragma once

#include <string>

namespace Receiver
{
	namespace ReceiverLib
	{
		class ReceiveData
		{
		public:
			ReceiveData() = default;
			void start(std::string&);
		};
	}
}
