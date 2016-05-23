// file_translation.h
#ifndef FILE_TRANS
#define FILE_TRANS
#include "word_library.h"
#include "search_strategy.h"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

class file_translation{
private:
	fstream fin, fout;
	int opened_properly;
public:
	file_translation(const string&);
	int is_opened_properly();
	void run();
};

#endif