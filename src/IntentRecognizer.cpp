#include "../include/IntentRecognizer.h"

using namespace std;

map<string,string> IntentRecognizer::synonyms = {
    {"weather","Weather"},
    {"temperature","Weather"},
    {"warm","Weather"},
    {"cold","Weather"},
    {"condition","Weather"},
    {"in","City"},
    {"at","City"},
    {"around","City"},
    {"fact","Fact"},
    {"truth","Fact"},
    {"info","Fact"},
    {"infos","Fact"},
    {"informations","Fact"},
    {"facts","Fact"},
    {"truths","Fact"},
    {"wisdoms","Fact"},
    {"information","Fact"},
    {"wisdom","Fact"},
    {"interest", "Fact"}
};

IntentRecognizer::IntentRecognizer(vector<string> text){
// remove punctuation ,:"!. and transform to lower case only, TODO: parallelize for speed
    for (string& token : text){
        token.erase(remove_if(token.begin(), token.end(), ::ispunct), token.end());
        transform(token.begin(), token.end(), token.begin(),
        [](unsigned char c){ return std::tolower(c); });
    }
    this->text = text;
}
    
string IntentRecognizer::getIntent(){
    string intent = "Intent: Get";
    for (int index=0; index < text.size(); ++index){
        if (IntentRecognizer::synonyms.count(text[index])) {
            if (IntentRecognizer::synonyms[text[index]] == "City" && index+1 < text.size()){
                intent += " "+(IntentRecognizer::synonyms[text[index]])+" ("+text[index+1] +")";
                continue;
            } else if (IntentRecognizer::synonyms[text[index]] == "Weather"){
                intent += " "+(IntentRecognizer::synonyms[text[index]]);
                continue;
            } else if((IntentRecognizer::synonyms[text[index]]) == "Fact"){
                intent += " "+(IntentRecognizer::synonyms[text[index]]);
                break;
            }
        }
    }
    return intent;
}




