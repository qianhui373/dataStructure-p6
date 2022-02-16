#include <iostream>
#include <fstream>

#include "dictionary.hpp"

void usage(char * exename){
  std::cout << "Usage: " << exename << " dict input\n\n";
  std::cout << "  dict: ASCII text file of words seperated by |\n";
  std::cout << "  input: ASCII text file\n";
}

int main(int argc, char *argv[])
{
  if(argc != 3){
    std::cerr << "Error: wrong number of arguments.\n";
    usage(argv[0]);
    return EXIT_FAILURE;
  }

  Dictionary dict;
  std::ifstream difs(argv[1]);
  if(!difs.is_open()){
    std::cerr << "Error: could not open dictionary file: " << argv[1] << ".\n";
    usage(argv[0]);
    return EXIT_FAILURE;
  }
  if(!dict.load(difs)){
    std::cerr << "Error: could not read dictionary.\n";
    usage(argv[0]);
    return EXIT_FAILURE;
  }
  difs.close();

  std::ifstream tifs(argv[2]);
  if(!tifs.is_open()){
    std::cerr << "Error: could not open text file: " << argv[2] << ".\n";
    usage(argv[0]);
    return EXIT_FAILURE;
  }

  WordList missed = spellcheck(dict, tifs);
  tifs.close();

  for(WordList::iterator it = missed.begin(); it != missed.end(); ++it){
    std::cout << it->word << " (" << it->line << "," << it->column << ")\n";
  }

  return EXIT_SUCCESS;
}
