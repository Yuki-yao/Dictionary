#include<vector>
#include<string>
#include<ctime>
#include"search_history_library.h"
using namespace std;

void search_history_library::input_search_history(string history)
{
        search_history newhistory(history);
        search_histories.push_back(newhistory);
}

vector<search_history> search_history_library::get_latest_history(string substring, int n)
{
        vector<search_history> feedbacks;
        int count = 0;
        for(int i = search_histories.size() - 1; i >= 0; i --)
        {
                if(search_histories[i].get_history_word().find(substring) == 0)
                {
                        feedbacks.push_back(search_histories[i]);
                        count++;
                        if(count >= n) break;
                }
        }
        return feedbacks;
}

void search_history_library::clear_search_history()
{
        search_histories.clear();
}

search_history::search_history(string _word): word(_word)
{
        time(&searchtime);
}

const string& search_history::get_history_word()
{
        return word;
}
