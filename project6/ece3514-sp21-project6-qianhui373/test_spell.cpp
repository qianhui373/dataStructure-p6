#include "catch.hpp"

#include <string>
#include <sstream>

#include "dictionary.hpp"

// TODO ADD YOUR TESTS

TEST_CASE("Test basic interface", "[spellcheck]") {

  Dictionary dict;

  std::string dstring = "to|be|or|not|that|is|the|question|push-pull|don't|can't";
  std::istringstream dstream(dstring);
  
  REQUIRE(dict.load(dstream));

  {
    std::string tstring = "To be or not to be, that is the question.";
    std::istringstream tstream(tstring);
    
    WordList list = spellcheck(dict, tstream);
    REQUIRE(list.empty());
  }

  {
    std::string tstring = "To be or not to be, that is the qeustion.";
    std::istringstream tstream(tstring);
    
    WordList list = spellcheck(dict, tstream);
    REQUIRE_FALSE(list.empty());
    MisspelledWord w = list.front();
    REQUIRE(w.word == "qeustion");
    REQUIRE(w.line == 1);
    REQUIRE(w.column == 33);
  }
  
}


////////////////
TEST_CASE("Test more", "[spellcheck]") {

    Dictionary dict;

    std::string dstring = "a|b|c|d|a-b";
    std::istringstream dstream(dstring);

    REQUIRE(dict.load(dstream));

    {
        std::string tstring = ". - \n 'dict -a a-b ";
        std::istringstream tstream(tstring);

        WordList list = spellcheck(dict, tstream);
        REQUIRE(list.size() == 1);
        MisspelledWord w = list.front();
        REQUIRE(w.word == "dict");
        REQUIRE(w.line == 2);
        REQUIRE(w.column == 3);
    }
}

TEST_CASE("Test more row", "[spellcheck]") {
    Dictionary dict;

    std::string dstring = "a|b|c|d|a-b";
    std::istringstream dstream(dstring);

    REQUIRE(dict.load(dstream));
    {
        std::string tstring = ". - \n dict -a a-b \n aab";
        std::istringstream tstream(tstring);

        WordList list = spellcheck(dict, tstream);
        REQUIRE(list.size() == 2);
        MisspelledWord w = list.front();
        REQUIRE(w.word == "dict");
        REQUIRE(w.line == 2);
        REQUIRE(w.column == 2);

        MisspelledWord w1 = list.back();
        REQUIRE(w1.word == "aab");
        REQUIRE(w1.line == 3);
        REQUIRE(w1.column == 2);
    }
}

