/*
 Jacob Fisher
 2/15/16
 Implements the Flesch Readability Index
 */

#include <iostream>
#include <string>
using namespace std;

//function prototypes
bool is_letter(string c);
bool is_vowel(string c);
bool is_punctuation(string c);
bool is_space(string c);

int sentencesInString(string text);
int wordsInString(string text);
int syllablesInWord(string word);
int syllablesInString(string text);

double readabilityIndex(string text);

//returns whether a string of length 1 is a letter or not
bool is_letter(string c) {
    if ((!is_punctuation(c)) && (!is_space(c))) {
        return true;
    }
    
    else {
        return false;
    }
}

//takes a string on length 1 and returns if it is a vowel or not
bool is_vowel(string c) {
    
    if (c.length() > 1) {
        return false;
    }
    
    else {
        if ((c == "a") || (c == "e") || (c == "i") || (c == "o") || (c == "u") || (c == "y") || (c == "A") || (c == "E") || (c == "I") || (c == "O") || (c == "U") || (c == "Y")) {
            return true;
        }
        
        else {
            return false;
        }
    }
}

//takes a string on length 1 and returns if it is a punctuation mark or not
bool is_punctuation(string c) {
    
    if (c.length() > 1) {
        return false;
    }
    
    else {
        if ((c == "!") || (c == "?") || (c == ".") || (c == ":") || (c == ";")) {
            return true;
        }
        
        else {
            return false;
        }
    }
}

//takes a string of length 1 and returns if it is a space or not
bool is_space(string c) {
    
    if (c.length() > 1) {
        return false;
    }
    
    else {
        if (c == " ") {
            return true;
        }
        
        else {
            return false;
        }
    }
}

//returns the number of sentences in a given string
int sentencesInString(string text) {
    
    int count = 0;
    
    for (int i = 0; i < text.length(); i++) {
        if (is_punctuation(text.substr(i, 1))) {
            count++;
        }
    }
    
    return count;
}

//returns the number of words in a given string
int wordsInString(string text) {
    
    //counts upwords for the first letter of every word
    int count = 0;
    
    //while iterating through a string, this variable keeps track of if the current character can be the start of a new word, or if it cannot because a word is already in progress
    bool newWordPossible = true;
    
    string c; //the current character we are dealing with while iterating through the string
    
    for (int i = 0; i < text.length(); i++) {
        
        c = text.substr(i, 1);
        
        //if the current letter we are dealing with is neither punctuation, a space, nor a letter in the middle of the word, it is the first letter of a new word so we can increase word count
        if ((!is_punctuation(c)) && (!is_space(c)) && (newWordPossible == true)) {
            count++;
            newWordPossible = false;
        }
        
        //if there is a space or punctuation mark, the following character may be the start of a new word
        else if (is_punctuation(c) || is_space(c)) {
            newWordPossible = true;
        }
    }
    
    return count;
}

//returns the number of syllables in a given word
int syllablesInWord(string word) {
    
    //counts upwords when it comes across the first letter of a new vowel group
    int count = 0;
    
    //while iterating through a word, this variable keeps track of if the current character can be the start of a new vowel group, or if it cannot because a vowel group is already in progress
    bool newGroupPossible = true;
    
    string c; //the current character we are dealing with while iterating through the string
    
    if (word.length() == 0) {
        return 0;
    }
    
    for (int i = 0; i < word.length(); i++) {
        
        c = word.substr(i, 1);
        
        //if the current letter we are dealing with is a vowel and we are not already in the midst of a vowel group, it is the first letter of a new group so we can increase vowel group count
        if ((is_vowel(c)) && (newGroupPossible == true)) {
            count++;
            newGroupPossible = false;
        }
        
        //if there is a non-vowel, the following character may be the start of a new word
        else if (!is_vowel(c)) {
            newGroupPossible = true;
        }
    }
    
    //if the last letter of the word is a single e, decrease the syllable count by one
    if (word.length() > 2) {
        int len = int(word.length());
        if ((word.substr(len-1, 1) == "e") && (word.substr(len-2, 1) != "e") && (!is_vowel(word.substr(len-2, 1)))) {
            count -= 1;
        }
    }
    
    if (count < 1) {
        count = 1;
    }
    
    return count;
}

//returns the number of syllables in a given string
int syllablesInString(string text) {
    int start = 0;
    
    int count = 0;
    
    int len = 0;
    
    string word;
    
    string c;
    
    bool newWordPossible = true;
    
    for (int i = 0; i < text.length(); i++) {
        c = text.substr(i, 1);
        
        if (is_letter(c) && newWordPossible) {
            start = i;
            newWordPossible = false;
            len++;
        }
        
        else if (is_letter(c)) {
            len++;
        }
        
        else {
            word = text.substr(start, len);
            count += syllablesInWord(word);
            newWordPossible = true;
            start = 0;
            len = 0;
        }
        
        //special case for when the final character is a letter, since it takes the presence of a non-letter after a word to cause the syllables of that word to be calculated
        if ((i == text.length() - 1) && (newWordPossible == false)){
            word = text.substr(start, len);
            count += syllablesInWord(word);
        }
    }
    
    return count;
}

//returns the readability index of a given phrase
double readabilityIndex(string text) {
    
    double numWords = (double)wordsInString(text);
    double numSentences = (double)sentencesInString(text);
    double numSyllables = (double)syllablesInString(text);
    
    double myIndex = 206.835 - 84.6 * (numSyllables/numWords) - 1.015 * (numWords/numSentences);
    
    return myIndex;
    
}

int main() {
    
    string phrase;
    
    cout << "Please type in a phrase:" << endl;
    getline(cin, phrase);
    
    cout << "Number of syllables: " << syllablesInString(phrase) << endl;
    cout << "Number of words: " << wordsInString(phrase) << endl;
    cout << "Number of sentences: " << sentencesInString(phrase) << endl;
    cout << "Readability index: " << readabilityIndex(phrase) << endl;
    
    system("pause");
    return 0;
}