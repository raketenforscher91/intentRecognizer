#include <gtest/gtest.h>
#include "../include/IntentRecognizer.h"

using namespace std;

TEST(GetMeAFact, IntentRecognizer) {
    vector<string> in = {"Get","me","a","Fact!"};
    EXPECT_EQ("Intent: Get Fact", IntentRecognizer(in).getIntent());
}

TEST(HowIsTheWeather, IntentRecognizer) {
    vector<string> in = {"How","is","the","Weather?"};
    EXPECT_EQ("Intent: Get Weather", IntentRecognizer(in).getIntent());
}

TEST(HowIsTheWeatherIn, IntentRecognizer) {
    vector<string> in = {"How","is","the","Weather", "in" ,"Paris?"};
    EXPECT_EQ("Intent: Get Weather City (paris)", IntentRecognizer(in).getIntent());
}

TEST(TellMeSomethingOfInterest, IntentRecognizer) {
    vector<string> in = {"Tell","me","something","of", "interest"};
    EXPECT_EQ("Intent: Get Fact", IntentRecognizer(in).getIntent());
}

TEST(CheckPunctuation, IntentRecognizer) {
    vector<string> in = {"Tell","me",",.-a:","fact!"};
    EXPECT_EQ("Intent: Get Fact", IntentRecognizer(in).getIntent());
}

TEST(HowWarm, IntentRecognizer) {
    vector<string> in = {"How","warm","is","it","in","Rom?"};
    EXPECT_EQ("Intent: Get Weather City (rom)", IntentRecognizer(in).getIntent());
}

TEST(GiveInfo, IntentRecognizer) {
    vector<string> in = {"Give","me","some","info!"};
    EXPECT_EQ("Intent: Get Fact", IntentRecognizer(in).getIntent());
}

TEST(MalformedInput, IntentRecognizer) {
    vector<string> in = {"How","warm","is","it","in"};
    EXPECT_EQ("Intent: Get Weather", IntentRecognizer(in).getIntent());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
