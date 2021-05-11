#ifndef SPLIT_H
#define SPLIT_H

#include <vector>
#include <string>

using namespace std;

/**
*	Split the string "str" by divisor d
*
*	remarks:
*
*  ("",  '.') -> [""]
*  ("11", '.') -> ["11"]
*  ("..", '.') -> ["", "", ""]
*  ("11.", '.') -> ["11", ""]
*  (".11", '.') -> ["", "11"]
*  ("11.22", '.') -> ["11", "22"]
*/
vector<string> Split(const string& str, char d);

#endif