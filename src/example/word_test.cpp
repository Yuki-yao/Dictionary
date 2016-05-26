#include <iostream>
#include <string>
#include <vector>
#include "word_library.h"
#include "search_history_library.h"
#include "review_history_library.h"
#include "search_strategy.h"
#include "file_translation.h"
#include "review_strategy.h"
#include "test_strategy.h"

using namespace std;
extern word_library word_lib;


int main()
{
	// review_strategy today_review;
	cout << "Loaded.\n";
	word_meaning_test test;
    while(!test.is_completed()){
        pair<int, int> x = test.get_state();
        pair<string, string> q = test.get_question();
        cout << x.first << " " << x.second << " level " << test.get_level()+1 << endl;
        cout << q.first << endl << q.second << endl;
        int i;
        cin >> i;
        test.input_your_answer(i);
    }    
    cout << test.get_result() << endl;
    return 0;

}
