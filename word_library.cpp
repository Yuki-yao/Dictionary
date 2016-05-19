#include<vector>
#include"word_library.h"
#include<string>
#include<map>
#include<set>
using namespace std;

word_library word_lib;

void word_library::insert_word(word new_word)
{
        int position = -1;
        for(int i = 0; i < words.size(); i ++)
        {
                if(new_word.get_word_name() == words[i].get_word_name())
                {
                        position = i;
                        break;
                }
        }
        if(position >= 0)
                words[position].insert_features(new_word.get_feature(0));
        else
        {
                words.push_back(new_word);
                wordmap[new_word.get_word_name()] = &new_word;
                newwords.insert(new_word.get_word_name());
        }
}

word::word(string _word_name):word_name(_word_name){}

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

feature::feature(string _pos, string _meaning): pos(_pos), meaning(_meaning){}

void feature::insert_examples(string example)
{
        examples.push_back(example);
}
