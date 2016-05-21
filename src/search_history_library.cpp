#include<vector>
#include<string>
#include<ctime>
#include"search_history_library.h"
using namespace std;

void search_history_library::insert_search_history(string history)
{
        search_histories.push_back(history);
}

vector<string> search_history_library::get_latest_history(string substring, int n)
{
        vector<string> feedbacks;
        int count = 0;
        for(int i = search_histories.size() - 1; i >= 0; i --)
        {
                if(search_histories[i].find(substring) == 0)
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
        //clear the file...
}
