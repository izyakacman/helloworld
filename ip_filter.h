#ifndef IP_FILTER_H
#define IP_FILTER_H

#include <vector>

using namespace std;

/**
	Print filtered ip addresses

	nType = 0 - first number == 1
	nType = 1 - first number == 46 and second number == 70
	nType = 1 - any number == 46
*/
void Filter(const vector<vector<int>>& ipPool, int nType);

#endif