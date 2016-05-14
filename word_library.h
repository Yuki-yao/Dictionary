#ifndef WORD_LIBRARY_H_INCLUDED
#define WORD_LIBRARY_H_INCLUDED
#include<string>
#include<vector>
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
        void insert_word_library(word new_word);
private:
        vector<word> words;
};


#endif // WORD_LIBRARY_H_INCLUDED
