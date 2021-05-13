#include <iostream>

#include "ip_print.h"

/**
	Print IP address
*/
void PrintIp(const vector<int>& ipAddress)
{
	for (auto ip_part = ipAddress.cbegin(); ip_part != ipAddress.cend(); ++ip_part)
	{
		if (ip_part != ipAddress.cbegin())
		{
			cout << ".";

		}
		cout << *ip_part;
	}

	cout << endl;
}

/**
	Print IP Pool
*/
void IpPoolPrint(const vector<vector<int>>& ipPool)
{
	for (const auto& ip : ipPool)
	{
		PrintIp(ip);
	}
}