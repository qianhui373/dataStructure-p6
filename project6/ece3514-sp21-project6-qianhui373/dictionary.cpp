#include "dictionary.hpp"

// implement Dictionary class

// implement spellcheck function
#include <iostream>
#include <fstream>
#include <cstddef>
#include <stdexcept>
#include <cmath>

#include <string.h>
#include <ctype.h>

Dictionary::Dictionary() {

}

bool Dictionary::load(std::istream& stream) {
    char word[128] = { 0 };
    while (!stream.eof()) {
        stream.getline(word, 128, '|');
        for (int i = 0; i < strlen(word); i++) {
            if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || ((word[i] == '\'' || word[i] == '-') && (i > 0))) {
                word[i] = tolower(word[i]);
            }
            else {
                return false;
            }
        }
        std::string str = word;
        //std::cout << str << std::endl;
        if (str.size()) {
            //std::cout << str << std::endl;
            if (dict_.find(str) == dict_.end()) {
                dict_.emplace(str);
            }
            else {
                return false;
            }
        }
    }
    return true;
}




// implement spellcheck function
WordList spellcheck(const Dictionary& dict, std::istream& stream) {
    char word[128] = { 0 };
    int row = 1;
    int col = 1;
    int i = 0;
    char c;
    std::list<MisspelledWord> result;
    memset(word, 0, sizeof(word));
    while (stream.get(c)) {

        //stream.get(c);
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || ((c == '\'' || c == '-') && (i > 0))) {
            word[i] = tolower(c);
            i++;
        }
        else {
            if (i > 0) {
                if (!dict.contains(word)) {
                    //std::cout << word << " " <<row << " " <<col << std::endl;
                    MisspelledWord missWord(word, row, col - strlen(word));
                    result.push_back(missWord);
                }
            }
            i = 0;
            memset(word, 0, sizeof(word));
            if (c == '\n') {
                row++;
                col = 0;
            }
        }
        col++;
    }
    if (i > 0) {
        if (!dict.contains(word)) {
            MisspelledWord missWord(word, row, col - strlen(word));
            result.push_back(missWord);
        }

    }
    return result;
}


bool Dictionary::contains(std::string word) const {
    for (int i = 0; i < word.size(); i++) {
        word[i] = tolower(word[i]);
    }
    if (dict_.find(word) == dict_.end()) {
        return false;
    }
    else {
        return true;
    }
}