#include<vector>
#include"word_library.h"
#include<string>
using namespace std;

void word_library::insert_word_library(word new_word)
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
                words[position].insert_features(new_word);
        else
                words.push_back(new_word);
}

void word::insert_features(feature new_feature)
{
        features.push_back(new_feature);
}

void word::insert_features(word new_word)
{
        features.push_back(new_word.features[0]);
}

const string& word::get_word_name()
{
        return word_name;
}

void feature::insert_examples(string example)
{
        examples.push_back(example);
}
