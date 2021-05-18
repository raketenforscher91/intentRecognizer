
#include "../include/IntentRecognizer.h"
#include <iostream>



int main (int argc, char *argv[]) {
    if (argc == 1){
        cout << "No input" << "\n";
        return 0;
    }
    IntentRecognizer intentRecognizer(vector<string>(argv + 1, argv + argc));
    std::cout << intentRecognizer.getIntent() << "\n";
    return 0;
}
