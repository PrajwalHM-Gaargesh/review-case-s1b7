#pragma once
#include "GlobalVars.h"

#include <vector>
#include <string>

class ColumnFilter {
private:
	std::vector<std::string> _argList;
	std::vector<std::string> _columnsToFilter;
public:
	explicit ColumnFilter(std::vector<std::string> x);
	bool filterColumns();
};