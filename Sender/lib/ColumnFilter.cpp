#include "ColumnFilter.h"

#include <iostream>
#include <vector>
#include <string>

ColumnFilter::ColumnFilter(std::vector<std::string> x) {
	_argList = x;
	for (size_t i = 2; i < _argList.size(); i++) {
		_columnsToFilter.push_back(_argList[i]);
	}
}

void matchfilterWithHeaderList(std::vector<bool>& hFlag, bool& fFlag, std::string filter) {
	for (size_t headeri = 0; headeri < headerList.size(); headeri++) {
		if (headerList[headeri].compare(filter) == 0) {
			hFlag.push_back(true);
			headerList.erase(headerList.begin() + headeri);
			fFlag = false;
		}
	}
}


bool areFiltersValid(std::vector<std::string> filterList) {
	//std::cout << "areFiltersValid called" << std::endl;
	std::vector<bool> headerFlag;
	bool isFilterInvalid;
	for (size_t filteri = 0; filteri < filterList.size(); filteri++ ) {
		isFilterInvalid = true;
		matchfilterWithHeaderList(headerFlag, isFilterInvalid, filterList[filteri]);
		if (isFilterInvalid) { return false; }
	}
	return true;
}

bool ColumnFilter::filterColumns() {
 
	if (areFiltersValid(_columnsToFilter)) {
		for (auto iterVec : _columnsToFilter) {
			parsedCsvFile.erase(iterVec);
		}
		return true;
	}

	return false;
}