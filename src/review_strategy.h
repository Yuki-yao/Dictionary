// review_strategy.h 
#ifndef REVIEW
#define REVIEW
#include <iostream>
#include "word_library.h"
#include "review_history_library.h"

class review_strategy{
private:
	vector<pair<string, int> > list;
	int it;
	// void get_today_list();
	set<string> word_to_review;
public:
	review_strategy();
	~review_strategy();
	void get_today_list();
	string get_next_word();
	void input_performance(int);
	int all_correct();
};

#endif