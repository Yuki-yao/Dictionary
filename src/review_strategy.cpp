// review_strategy.cpp
#include "review_strategy.h"
#define max_list_len 100

extern review_history_library review_history_lib;
extern word_library word_lib;

review_strategy::review_strategy(){
	fstream fin;
	int m;
	fin.open("../res/review.dat");
	list.clear();
	it = 0;
	if(fin){
		fin >> m >> it;
		for(int i = 0;i<m;i++){
			string str;
			int score;
			fin >> str >> score;
			if(score >= 5) continue;
			list.push_back(make_pair(str, score));
			word_to_review.insert(str);
			cout << str << " " << score << endl;
		}
	}
	get_today_list();
}

review_strategy::~review_strategy(){
	fstream fout;
	fout.open("../res/review.dat");
	fout << list.size() << " " << it << endl;
	for(auto& i : list){
		fout << i.first << endl;
	}
}

void review_strategy::get_today_list(){
	// int p[10];
	// p[0] = 1;
	// for(int i = 1;i<10;i++) p[i] = p[i-1] << 1;
	// for(int i = 1;i<10;i++){
	// 	vector<string> now = review_history_lib.get_list(p[i]);
	// 	for(auto j : now)
	// 		list.push_back(make_pair((*j), 5));
	// }	
	while(list.size() < max_list_len){
		// cout << "_____" << endl;
		string new_word = word_lib.get_random_new_word();//haven't pan chong
		list.push_back(make_pair(new_word, 0));
	}
}

string review_strategy::get_next_word(){
	return list[it].first;
}

// void review_strategy::input_performance(int i){
// }

// string review_strategy::get_next_word(){
// 	return string("happy");
// }

void review_strategy::input_performance(int i){
	list[it].second += i;
	if(!i) list[it].second = 0;
	it = (it+1) % list.size();
}

int review_strategy::all_correct(){
	int p = 1;
	for(auto &i:list)
		if(i.second < 5) p =0;
	return p;
}