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
        int frequency;
public:
        void insert_examples(string example);
};

class word
{
public:
        word(string _word_name);
        void insert_features(feature new_feature);
        void insert_features(word new_word);
        const string& get_word_name();
private:
        string word_name;
        vector<feature> features;
};

class word_library
{
public:
        void insert_word(word new_word);
private:
        vector<word> words;
        map<string, word*> wordmap;
        set<string> newwords;
friend class review_history_library;
};

#endif // WORD_LIBRARY_H_INCLUDED
