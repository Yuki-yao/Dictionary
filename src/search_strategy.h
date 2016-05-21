//search_strategy.h
#ifndef SEARCH
#define SEARCH
#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef vector<string> result_list;

class search{
private:
	int result_amout;
public:
	search(int){}
	virtual result_list get_result(string) = 0;
};

class search_in_history:search{

};


#endif
