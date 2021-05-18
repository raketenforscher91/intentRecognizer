

#ifndef IntentRecognizer_h
#define IntentRecognizer_h

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;



class IntentRecognizer{
private:
    vector<string> text{};
    // synonym database TODO: load from JSON or external database
    
public:
    static map<string,string> synonyms;
    IntentRecognizer(vector<string> text);
    string getIntent();
};
#endif
