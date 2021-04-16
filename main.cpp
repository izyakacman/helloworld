#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>

using namespace std;

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
vector<string> split(const string& str, char d)
{
	vector<string> r;

	string::size_type start = 0;
	string::size_type stop = str.find_first_of(d);
	while (stop != string::npos)
	{
		r.push_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}

	r.push_back(str.substr(start));

	return r;
}

/**
	Print IP address
*/
template<typename T>
void PrintIp(const T& ipAddress)
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
template<typename T>
void IpPoolPrint(const T& ipPool)
{
	for (const auto& ip : ipPool)
	{
		PrintIp(ip);
	}
}

/**
	Print filtered ip addresses

	nType = 0 - first number == 1
	nType = 1 - first number == 46 and second number == 70
	nType = 1 - any number == 46
*/
template<typename T>
void Filter(const T& ipPool, int nType)
{
	for_each(ipPool.cbegin(), ipPool.cend(), [nType](const typename T::value_type& v) {

		if ((nType == 0 && v.at(0) == "1") ||
			(nType == 1 && v.at(0) == "46" && v.at(1) == "70") ||
			(nType == 2 && find(begin(v), end(v), "46") != end(v)))
			PrintIp(v);
		});
}

/**
	Reverse lexicographically sort
*/
template<typename T>
void IpSort(T& ipPool)
{
	sort(ipPool.begin(), ipPool.end(), [](const typename T::value_type& v1, const T::value_type& v2)
		{
			string s1, s2;

			for (int i = 0; i < 2; ++i)
			{
				for (const auto& s : ((i) ? v1 : v2))
				{
					((i) ? s1 : s2).append(3 - s.size(), '0');
					((i) ? s1 : s2) += s;
				}
			}

			return stoull(s1) > stoull(s2);
		});
}

int main (int, char **)
{
	try
	{
		// Ôàéë èñõîäíûõ äàííûõ

		ifstream fileInputStream("ip_filter.tsv");

		if (!fileInputStream)
		{
			cerr << "Open file error\n";
			throw 0;
		}

		vector<vector<string>> ip_pool;

		for (string line; getline(fileInputStream, line);)
		{
			vector<string> v = split(line, '\t');
			ip_pool.push_back(split(v.at(0), '.'));
		}

		// Reverse lexicographically sort

		IpSort(ip_pool);

		// Print all

		IpPoolPrint(ip_pool);

		// Filter print

		for (int i = 0; i < 3; ++i)
			Filter(ip_pool, i);

		// 222.173.235.246
		// 222.130.177.64
		// 222.82.198.61
		// ...
		// 1.70.44.170
		// 1.29.168.152
		// 1.1.234.8

		// TODO filter by first byte and output
		// ip = filter(1)

		// 1.231.69.33
		// 1.87.203.225
		// 1.70.44.170
		// 1.29.168.152
		// 1.1.234.8

		// TODO filter by first and second bytes and output
		// ip = filter(46, 70)

		// 46.70.225.39
		// 46.70.147.26
		// 46.70.113.73
		// 46.70.29.76

		// TODO filter by any byte and output
		// ip = filter_any(46)

		// 186.204.34.46
		// 186.46.222.194
		// 185.46.87.231
		// 185.46.86.132
		// 185.46.86.131
		// 185.46.86.131
		// 185.46.86.22
		// 185.46.85.204
		// 185.46.85.78
		// 68.46.218.208
		// 46.251.197.23
		// 46.223.254.56
		// 46.223.254.56
		// 46.182.19.219
		// 46.161.63.66
		// 46.161.61.51
		// 46.161.60.92
		// 46.161.60.35
		// 46.161.58.202
		// 46.161.56.241
		// 46.161.56.203
		// 46.161.56.174
		// 46.161.56.106
		// 46.161.56.106
		// 46.101.163.119
		// 46.101.127.145
		// 46.70.225.39
		// 46.70.147.26
		// 46.70.113.73
		// 46.70.29.76
		// 46.55.46.98
		// 46.49.43.85
		// 39.46.86.85
		// 5.189.203.46



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
