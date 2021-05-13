#include <algorithm>

#include "ip_filter.h"
#include "ip_print.h"

/**
	Print filtered ip addresses

	nType = 0 - first number == 1
	nType = 1 - first number == 46 and second number == 70
	nType = 1 - any number == 46
*/
void Filter(const vector<vector<int>>& ipPool, int nType)
{
	for_each(ipPool.cbegin(), ipPool.cend(), [nType](const auto& v) {

		if ((nType == 0 && v.at(0) == 1) ||
			(nType == 1 && v.at(0) == 46 && v.at(1) == 70) ||
			(nType == 2 && find(begin(v), end(v), 46) != end(v)))
			PrintIp(v);
		});
}