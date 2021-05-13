#include <algorithm>

#include "ip_sort.h"

/**
	Reverse lexicographically sort
*/
void IpSort(vector<vector<int>>& ipPool)
{
	sort(ipPool.begin(), ipPool.end(), [](const auto& v1, const auto& v2)
		{
			return v1 > v2;
		});
}