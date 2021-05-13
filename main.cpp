#include <iostream>
#include <vector>
#include <fstream>

#include "split.h"
#include "ip_filter.h"
#include "ip_print.h"
#include "ip_sort.h"

using namespace std;

int main ()
{
	try
	{
		vector<vector<int>> ip_pool;

//#define DATA_FROM_FILE
#ifdef DATA_FROM_FILE
		// Input data

		ifstream fileInputStream("ip_filter.tsv");

		if (!fileInputStream)
		{
			cerr << "Open file error\n";
			throw 0;
		}

		for (string line; getline(fileInputStream, line);)
#else
		for (string line; getline(cin, line);)
#endif
		{
			vector<string> v = Split(line, '\t');
			vector<string> ip = Split(v.at(0), '.');
			vector<int> ip_int;
			for (const auto& s : ip) ip_int.push_back(stoi(s));

			ip_pool.push_back(ip_int);
		}

		// Reverse lexicographically sort

		IpSort(ip_pool);

		// Print all

		IpPoolPrint(ip_pool);

		// Filter print

		for (int i = 0; i < 3; ++i)
			Filter(ip_pool, i);
			
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
	catch (...)
	{
		cerr << "Unexpected exception\n";
	}

	return 0;
}
