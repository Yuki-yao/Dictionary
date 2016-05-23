#include <iostream>
#include <string>
#include <vector>
#include "word_library.h"
#include "search_history_library.h"
#include "review_history_library.h"

using namespace std;
extern word_library word_lib;

int main()
{
	cout << "Loaded.\n";
	word_library::iterator it;
	it = word_lib.end()-1;
	cout << it->get_word_name() << endl;
    string nword;
    cin >> nword;
    while(nword != "xxxxx")
	{
		for(it = word_lib.begin(); it != word_lib.end(); it ++)
		{
			if(it->get_word_name() == nword)
			{
				word::iterator it2;
                cout << nword << endl;
				for(it2 = it->begin(); it2 != it->end(); it2 ++)
				{
					cout << it2->get_pos() << endl;
					cout << it2->get_meaning() << endl;
					cout << endl;
				}
				break;
			}
		}
		if(it == word_lib.end()) cout << "Not found!\n" << endl;
		cin >> nword;
	}
    cout << "Hello world!" << endl;
    return 0;
}
