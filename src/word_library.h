#ifndef WORD_LIBRARY_H_INCLUDED
#define WORD_LIBRARY_H_INCLUDED
#include<string>
#include<vector>
#include<map>
#include<set>
#include<fstream>
using namespace std;

class feature
{
        string pos;//part of speech
        string meaning;
        vector<string> examples;
public:
        feature(string& _pos, string& _meaning);
        feature();
        void insert_examples(string example);
        const string& get_pos();
        const string& get_meaning();
        void load_feature(string&, string&);
};

class word
{
public:
	typedef vector<feature>::iterator iterator;
        word(string _word_name);
        void insert_features(feature new_feature);
        const string& get_word_name();
        const vector<feature>& get_features();
        const feature& get_feature(int i);//get the i-th feature in the features
        void change_level(int n);
        iterator begin();
        iterator end();
        int get_level();
private:
        string word_name;
        int level;
        vector<feature> features;
friend class word_library;
};

class word_library
{
public:
        typedef map<string, word*>::iterator iterator;
        void insert_word(string&);
        word_library();
        iterator begin();
        iterator end();
private:
        map<string, word*> word_map;
        set<string> word_set;
        set<string> newwords;
        string _word_name;
        ifstream fin;
friend class review_history_library;
};

#endif // WORD_LIBRARY_H_INCLUDED
