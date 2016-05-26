// test_strategy.cpp
#include "test_strategy.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_STATE 10
#define MIN_CORRECTNESS 8


word_meaning_test::word_meaning_test(){
	srand(time(0));
	clear();
	for(int i = 0;i<level_count;i++){
		fstream fin;
		fin.open(string("../data/level"+to_string(i)+".dat").c_str(), fstream::in);
		for(int j = 0;j < word_per_level;j++){
			string str;
			fin >> str;
			word_list[i].push_back(str);
		}
		random_shuffle(word_list[i].begin(), word_list[i].end());
		// for(int j = 0;j<20;j++){
		// 	cout << word_list[i][j] << endl;
		// }
	}
}

int word_meaning_test::is_completed(){
	return is_finished;
}

int word_meaning_test::get_result(){
	return result;
}

int word_meaning_test::get_level(){
	return stage;
}

pair<int, int> word_meaning_test::get_state(){
	return make_pair(state+1, MAX_STATE);
}

pair<string, string> word_meaning_test::get_question(){
	this_answer = rand() % 17;
	if(this_answer > 8) this_answer = false;
	    else this_answer = true;
	string _meaning;    
	if(!this_answer){
		int wrong_answer = rand()%word_per_level;
		if(wrong_answer == state) this_answer = true;
		feature now_feature = search_strategy(word_list[stage][wrong_answer]).get_feature(0);
		_meaning = now_feature.get_meaning();
	}
	else{
		feature now_feature = search_strategy(word_list[stage][state]).get_feature(0);
		_meaning = now_feature.get_meaning();	
	}
	return make_pair(word_list[stage][state], _meaning);    
}

void word_meaning_test::input_your_answer(int answer){
	if(answer == this_answer)
		correct++;
    state++;
	if(state == MAX_STATE){
		if(correct >= MIN_CORRECTNESS){
			stage++;
			if(stage == level_count){
				is_finished = 1;
				result = level_count*word_per_level;
				return;
			}
			state = 0;
			return;
		}
		is_finished = 1;
		result = stage*word_per_level;
		return;
	}
}

void word_meaning_test::clear(){
	state = stage = correct = is_finished = 0;
	for(int i = 0;i<level_count;i++)
		word_list[i].clear();
}