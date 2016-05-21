#include<vector>
#include"word_library.h"
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<fstream>
using namespace std;

word_library word_lib;

void word_library::insert_word(word new_word)
{
        vector<word>::reverse_iterator rit;
        for(rit = words.rbegin(); rit != words.rend(); rit ++)
        {
                if(new_word.get_word_name() == rit->get_word_name()) break;
        }
        if(rit != words.rend())
                rit->insert_features(new_word.get_feature(0));
        else
        {
                words.push_back(new_word);
                wordmap.insert(pair<string, word&>(new_word.get_word_name(), words.back()));
                newwords.insert(new_word.get_word_name());
        }
}

word_library::word_library()
{
        ifstream fin;
        fin.open("../data/firststep");
        if(!fin)
        {
                cout << "Open error!" << endl;
                return;
        }

        string _word_name, _pos, _meaning;
        while(fin >> _word_name)
        {
                word new_word(_word_name);
                fin >> _pos >> _meaning;
                feature new_feature(_pos, _meaning);
                new_word.insert_features(new_feature);
                insert_word(new_word);
        }

        fin.close();

        fin.open("");
        if(!fin)
        {
                cout << "Open error!" << endl;
                return;
        }
        vector<string> f_words;
        string f_word;
        while(fin >>f_word)
        {
                f_words.push_back(f_word);
        }
        fin.close();

        int num = f_words.size() / 5;
        vector<string>::iterator vit = f_words.begin();
        for(int i = 1; i <= 5; i ++)
                for(int j = 0 ; j < num; vit ++)
                {
                        map<string, word&>::iterator mit;
                        mit = wordmap.find(*vit);
                        if(mit != wordmap.end())
                                mit->second.change_level(i);
                }

}

word::word(string _word_name):word_name(_word_name), level(3){}

void word::change_level(int n){level = n;}

void word::insert_features(feature new_feature)
{
        features.push_back(new_feature);
}

const string& word::get_word_name()
{
        return word_name;
}

const vector<feature>& word::get_features()
{
        return features;
}

const feature& word::get_feature(int i)
{
        return features[i];
}

feature::feature(string _pos, string _meaning): pos(_pos), meaning(_meaning), level(3){}

void feature::insert_examples(string example)
{
        examples.push_back(example);
}
