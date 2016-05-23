#include <iostream>
#include <string>
#include <vector>
#include "word_library.h"
#include "search_history_library.h"
#include "review_history_library.h"
#include "search_strategy.h"
#include "file_translation.h"

using namespace std;
extern word_library word_lib;

int main()
{
	cout << "Loaded.\n";
	//auto it = word_lib.end()-1;
	//cout << it->get_word_name() << endl;
	cout << word_lib.get_random_new_word() << endl;
    string nword;
    cin >> nword;
    while(nword != "xxxxx")
	{
		search_strategy new_search(nword);
        cout << new_search.is_found() << " " << new_search.features_count() << endl;
        int cnt = new_search.features_count();
        for(int i = 0;i<cnt;i++){
            feature now_feature = new_search.get_feature(i);
            cout << now_feature.get_pos() << endl << now_feature.get_meaning() << endl;
        }
        cin >> nword;
	}

	string file_name;
    cin >> file_name;
    file_translation ft(file_name);
    ft.run();

    cout << "Hello world!" << endl;
    return 0;
}
