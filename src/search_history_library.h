#ifndef SEARCH_HISTORY_LIBRARY_H_INCLUDED
#define SEARCH_HISTORY_LIBRARY_H_INCLUDED
#include<string>
#include<vector>
using namespace std;

class search_history_library
{
public:
        void insert_search_history(string history);//only push_back
        vector<string> get_latest_history(string substring, int n);//return recent n records that include substring in a reverse-chronological format
        void clear_search_history();
private:
        vector<string> search_histories;
};

#endif // SEARCH_HISTORY_LIBRARY_H_INCLUDED
