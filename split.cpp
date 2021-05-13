

#include "split.h"

/**
*	Split the string "str" by divisor d
*/
vector<string> Split(const string& str, char d)
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

