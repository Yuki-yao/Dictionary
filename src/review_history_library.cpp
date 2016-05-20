#include"review_history_library.h"
#include"word_library.h"
#include<vector>
#include<string>
#include<ctime>
#include<set>
using namespace std;

extern word_library word_lib;

void review_history_library::insert_review_history(review_history new_history)
{
        time_t currenttime;
        time(&currenttime);
        struct tm *current = localtime(&currenttime);
        if(current->tm_year == lists[lists.size()].get_year() && current->tm_yday == lists[lists.size()].get_yday())
                lists[lists.size()].insert_review_history(new_history);
        else
        {
                review_list new_list(current->tm_year, current->tm_yday);
                lists.push_back(new_list);
                lists[lists.size()].insert_review_history(new_history);
        }
        if(new_history.get_remembered())
                word_lib.newwords.erase(new_history.get_word());
}

void review_history_library::clear_review_history()
{
        lists.clear();
        //clear the file...
}

const int& review_list::get_year()
{
        return year;
}

const int& review_list::get_yday()
{
        return yday;
}

void review_list::insert_review_history(review_history new_history)
{
        histories.push_back(new_history);
}

review_list::review_list(int _year, int _yday): year(_year), yday(yday){}

const string& review_history::get_word()
{
        return word;
}

bool review_history::get_remembered()
{
        return remembered;
}

review_history::review_history(string _word, bool _remembered): word(_word), remembered(_remembered){}
