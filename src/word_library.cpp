#include <vector>
#include "word_library.h"
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
using namespace std;

word_library word_lib;


void word_library::insert_word(string& _word_name)
{
    string pos, meaning;
    if(word_map.count(_word_name) == 0)
        word_map[_word_name] = new word(_word_name);
    auto now = word_map[_word_name];
    now->features.push_back(feature());
    getline(fin, pos);
    getline(fin, meaning);

    auto p = now->features.end()-1;
    p->load_feature(pos, meaning);
}

word_library::word_library()
{
    _word_name = "";
    fin.open("../data/firststep");

    if(!fin)
    {
        cout << "Open error!" << endl;
        return;
    }

    string _word_name, tmp;
    while(!getline(fin, _word_name).fail())
    {
    	if(_word_name == "") break;
        if(_word_name[0] >= 'A' && _word_name[0] <= 'Z')
            _word_name[0] -= ('A'-'a');
        insert_word(_word_name);
        if(getline(fin, tmp).fail()) break;
    }
    fin.close();

    fin.open("../data/word_frequency");
    if(!fin)
    {
        cout << "Open error!" << endl;
        return;
    }
    vector<string> f_words;
    string f_word;
    while(fin >> f_word)
    {
        f_words.push_back(f_word);
    }
    fin.close();


    int num = f_words.size() / 5;
    vector<string>::iterator vit = f_words.begin();
    for(int i = 1; i <= 4; i ++)
        for(int j = 0 ; j < num; j ++, vit ++)
        {
            if(word_map.count(*vit) != 0)
                word_map[*vit]->change_level(i);
        }
    while(vit != f_words.end())
	{
		if(word_map.count(*vit) != 0)
			word_map[*vit]->change_level(5);
		vit ++;
	}

}

word_library::iterator word_library::begin()
{
    return word_map.begin();
}

word_library::iterator word_library::end()
{
    return word_map.end();
}

word::word(string _word_name):word_name(_word_name), level(3){}

word::word():level(3){}

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

word::iterator word::begin()
{
	return features.begin();
}

word::iterator word::end()
{
	return features.end();
}

int word::get_level(){
    return level;
}

int word::features_count(){
    return features.size();
}

feature::feature(string& _pos, string& _meaning): pos(_pos), meaning(_meaning){}

feature::feature(){}

void feature::load_feature(string& _pos, string& _meaning){
    pos = _pos;
    meaning = _meaning;
}

void feature::insert_examples(string example)
{
    examples.push_back(example);
}

const string& feature::get_pos()
{
	return pos;
}

const string& feature::get_meaning()
{
	return meaning;
}
