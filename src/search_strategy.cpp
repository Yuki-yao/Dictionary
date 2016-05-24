// search_strategy.cpp
#include "search_strategy.h"
#include <iostream>

using namespace std;

extern word_library word_lib;

search_strategy::search_strategy(const string& _search_word):search_word(_search_word){
    word_library::iterator it;
    for(it = word_lib.begin(); it != word_lib.end(); it ++)
		{
			if((*it).second->get_word_name() == search_word)
			{
				result = *((*it).second);
				break;
			}
		}
	if(it == word_lib.end()) found = 0;
	    else found = 1;
	// cout << _search_word << " " << found << endl;    
}

int search_strategy::is_found(){
	return found;
}

int search_strategy::features_count(){
	if(!found) return -1;
	return result.features_count();
}

const feature& search_strategy::get_feature(int i){
	return result.get_feature(i);
}

int search_strategy::is_new_word(){
	return word_lib.is_new_word(result.get_word_name());
}

int search_strategy::get_level(){
	return result.get_level();
}