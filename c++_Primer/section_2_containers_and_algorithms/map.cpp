/*************************************************************************
	> File Name: map.cpp
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-31 14:41:40
 ************************************************************************/

#include <string>
#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	map<string, int> word_count;
	map<string, int>::iterator map_it = word_count.begin();
	cout << map_it->first;
	count << " " << map_it->second;
	map_it->first = "new key";
	++map_it->second;
}
