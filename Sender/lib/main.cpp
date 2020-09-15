#include "Sender.h"


#include <vector>
#include <string>

int main(int argc, char* argv[]) {
	CsvFileParser csvfp;
	ConsoleOutput coutput;
	Sender* send = new Sender(&csvfp, &coutput, argc, argv);

	send->start();

	return 0;
}