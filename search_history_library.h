#ifndef SEARCH_HISTORY_LIBRARY_H_INCLUDED
#define SEARCH_HISTORY_LIBRARY_H_INCLUDED
#include<string>
#include<vector>
#include<ctime>
using namespace std;

class search_history
{
        string word;
        time_t searchtime;
public:
        search_history(string _word);
        const string& get_history_word();
};

class search_history_library
{
public:
        void input_search_history(string history);
        vector<search_history> get_latest_history(string substring, int n);//return recent n records that include substring;
        void clear_search_history();
private:
        vector<search_history> search_histories;
};

#endif // SEARCH_HISTORY_LIBRARY_H_INCLUDED
