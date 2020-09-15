#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string>

#include "IOutput.h"
#include "GlobalVars.h"

class ConsoleOutput : public IOutput {
private:
public:
	bool write();
};