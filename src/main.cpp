#include <iostream>
#include <string>
#include <vector>
#include "word_library.h"
#include "search_history_library.h"
#include "review_history_library.h"
#include "search_strategy.h"
#include "file_translation.h"
#include "review_strategy.h"

using namespace std;
extern word_library word_lib;


int main()
{
	// review_strategy today_review;
	cout << "Loaded.\n";
	fstream fin;
    fin.open("../data/word_frequency", fstream::in);
    fstream fout;
    fout.open("../data/word_frequency1", fstream::out);
    string word;
    int i = 0;
    while(!fin.eof()){
        getline(fin, word);
        if(i % 100 == 0 )cout << i << endl;
        i++;
        auto new_search = search_strategy(word);
        if(new_search.is_found()) fout << word << endl;
    }
    return 0;

}
