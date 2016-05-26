// test_strategy.h
#ifndef TEST_STRATEGY
#define TEST_STRATEGY
#include "word_library.h"
#include "search_strategy.h"

#define level_count 20
#define word_per_level 800

class test_strategy{
public:
	virtual int is_completed() = 0;
	virtual int get_result() = 0;
};

class word_meaning_test:public test_strategy{
private:
	int state, stage, correct, is_finished, this_answer, result;
	vector<string> word_list[level_count];
public:
	void clear();
    word_meaning_test();
    int is_completed();
    int get_result();
    int get_level();
    pair<int, int> get_state();
    pair<string, string> get_question();
    void input_your_answer(int);
};
#endif