#include "Validator.h"

#include <iostream>
#include <vector>
#include <string>


bool Validator::validateHeaders() {
	if (headerList.size() == 0) {
		std::cout << "Invalid Headers in first row of csv file" << std::endl;
		return false;
	}
	return true;
}