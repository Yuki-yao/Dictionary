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
	string file_name;
    cin >> file_name;
    file_translation ft(file_name);
    ft.run();
    cout << "Hello world!" << endl;
    return 0;
}
