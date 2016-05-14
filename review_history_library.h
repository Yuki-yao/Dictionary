#ifndef REVIEW_HISTORY_LIBRARY_H_INCLUDED
#define REVIEW_HISTORY_LIBRARY_H_INCLUDED
#include<string>
#include<vector>
#include<ctime>
using namespace std;

class review_history
{
        string word;
        int grade;//0: not remembered; 1: vague; 2: remembered
};

class review_list
{
        int year;
        int yday;
        vector<review_history> histories;
public:
       const int& get_year();
       const int& get_yday();
       void insert_review_list(review_history new_history);
       review_list(int _year, int _yday);
};

class review_history_library
{
        vector<review_list> lists;
public:
        void insert_review_history(review_history new_history);//only push_back
        void clear_review_history();
};

#endif // REVIEW_HISTORY_LIBRARY_H_INCLUDED
