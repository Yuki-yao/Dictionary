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
extern review_history_library review_history_lib;
extern search_history_library search_history_lib;

int main()
{
	//review_strategy today_review;
	cout << "Loaded.\n";
	/*while(1){
	    cout << today_review.get_next_word() << endl << "Do you know this word?" << endl;
	    string respond;
        int j;
        getline(cin, respond);
        if(respond == "yes") j = 2;
            else if(respond == "no") j = 0;
                else if(respond == "quit") goto l1;
                    else j = 1;
	    today_review.input_performance(j);
	    if(today_review.all_correct()) break;
	}
l1:    cout << "Congratulations" << endl;*/


	/*vector<string> today_list = review_history_lib.get_list(0);
	for(int i = 0; i < today_list.size(); i ++)
		cout << today_list[i] << endl;
	for(int i = 0; i < 5; i ++)
	{
		string rand_word = word_lib.get_random_new_word();
		//cout << i << endl;
		review_history_lib.insert_review_history(rand_word);
	}
	vector<string> today_list2 = review_history_lib.get_list(0);
	for(int i = 0; i < 5; i ++)
		cout << today_list2[i] << endl;*/


	/*string a = "ass", b = "we", c = "can", d = "a";
	//search_history_lib.insert_search_history(a);
	//search_history_lib.insert_search_history(b);
	//search_history_lib.insert_search_history(c);
	vector<string> histories = search_history_lib.get_latest_history(d, 5);
	for(int i = 0; i < (int)histories.size(); i ++)
		cout << histories[i] << endl;*/

	string str = "apple", eg1 = "Apple is red.", eg2 = "Apple is big.", eg3 = "Apple is sweet.";
	search_strategy searchapple(str);

	searchapple.insert_examples(0, eg1);
	searchapple.insert_examples(0, eg2);
	feature a_feature = searchapple.get_feature(0);
	int count = a_feature.examples_count();
	cout << count << endl;
	cout << a_feature.get_example(0) << endl;
	cout << a_feature.get_example(1) << endl;

	searchapple.insert_examples(0, eg3);
	a_feature = searchapple.get_feature(0);
	count = a_feature.examples_count();
	cout << count << endl;
	cout << a_feature.get_example(0) << endl;
	cout << a_feature.get_example(1) << endl;
	cout << a_feature.get_example(2) << endl;
    return 0;
}
