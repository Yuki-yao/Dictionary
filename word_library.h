#ifndef WORD_LIBRARY_H_INCLUDED
#define WORD_LIBRARY_H_INCLUDED
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;

class feature
{
        string pos;//part of speech
        string meaning;
        vector<string> examples;
        int level;
public:
        feature(string _pos, string _meaning);
        void insert_examples(string example);
};

class word
{
public:
        word(string _word_name);
        void insert_features(feature new_feature);
        const string& get_word_name();
        const vector<feature>& get_features();
        const feature& get_feature(int i);//get the i-th feature in the features
        void change_level(int n);
private:
        string word_name;
        int level;
        vector<feature> features;
};

class word_library
{
public:
        void insert_word(word new_word);
        word_library();
private:
        vector<word> words;
        map<string, word&> wordmap;
        set<string> newwords;
friend class review_history_library;
};

#endif // WORD_LIBRARY_H_INCLUDED
