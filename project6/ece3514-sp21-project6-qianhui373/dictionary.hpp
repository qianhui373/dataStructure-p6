#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string>
#include <list>
#include <cstddef>
////////////////////////////////
#include <set>
#include <iostream>


struct MisspelledWord{
  std::string word;
  std::size_t line;
  std::size_t column;
  MisspelledWord(const std::string & w, std::size_t l, std::size_t c):
    word(w), line(l), column(c) {};
};

typedef std::list<MisspelledWord> WordList;

class Dictionary{
public:
  // default construct a dictionary
  Dictionary();

  // load a dictionary from a character stream
  bool load(std::istream & stream);

  // TODO
  bool contains(std::string word) const;


  /*bool contains(std::string word) const {
      for (int i = 0; i < word.size(); i++) {
          word[i] = tolower(word[i]);
      }
      if (dict_.find(word) == dict_.end()) {
          return false;
      }
      else {
          return true;
      }
  }*/


private:

  // TODO
    std::set<std::string> dict_;
};

// spell check all words in the input stream
WordList spellcheck(const Dictionary & dict, std::istream & stream);


#endif
