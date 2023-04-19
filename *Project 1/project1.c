/*
 * Name: Jin Jun Oh
 * EE312
 * SpellCheck
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helfpul. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I *insist* that you indent 
 * reasonably and consistently in your code. I strongly encourage you to avoid big functions
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */
// case-insensitive comparison
// if (wordk == dictionaryi || wordk == dictionaryi + ('a' -  'A') || wordk + ('a' -  'A') == dictionaryi) {
//}
// for (int i = 0; a[i] != '\0'; i++){}
// while (*a) {}
void nextn (char dictionary[], int *i){
    while (dictionary[*i] != '\n'){
        *i = *i +1 ;
    }
    *i = *i +1 ;
}
void nextnull (char dictionary[], int *i){
    while (dictionary[*i] != '\0'){
        *i = *i +1 ;
    }
}
//            isInDictionary(word, wordlength, words,&wordsi, dictionary);
void isInDictionary(char word[], int wsize, char words[], int *wordsi, char dictionary[]) {
    int d = 0; // pointer for dictionary
    int w = 0; // pointer for word

    int same = 0;
    while(dictionary[d] != '\0'){
        while (word[w] == dictionary[d] || word[w] == dictionary[d] + ('a' -  'A') || word[w] + ('a' -  'A') == dictionary[d]){ // if they are the same character
            d++;
            w++;
        }
        if (w == wsize && dictionary[d] == '\n'){
            same = 1;
            nextnull(dictionary, &d);
        }
        else{
            nextn(dictionary, &d);
            w = 0;
        }
    }
    // if you reached null terminator of dictionary and the word is not present in dictionary,
    if (same == 0) {
        for (int j = 0; j < wsize; j++) {
            words[*wordsi] = word[j];
            *wordsi = *wordsi +1;
        }
        *wordsi = 0;
    // expected output = ate, an, and
    }
}

int array_length(char* array) {
    int length = 0;
    while (array[length] != '\0') {
        length++;
    }
    return length;
}
void spellCheck(char article[], char dictionary[]) {
    int wordsi = 0;
    // placeholder int to store the size of article
    int articleSize = array_length(article);
    // placeholder int to store the size of dictionary
    int dictionarySize = array_length(dictionary);
    // placeholder string to store a word in article
    char word[articleSize];
    // placeholder int to store how long the word is
    int wordlength = 0;
    // placeholder string which stores the words that are not in the dictionary.
    char words[articleSize];

    // iterate through article to find a word
    // to be a word: character length >=0, Any letter Upper and Lower
    int index = 0;
    while (article[index] != '\0' && index <= articleSize) {
        // iterate through the article array and stop when it hits anything other than an alphabet
        while ((article[index] >= 'A' && article[index] <= 'Z') || (article[index] >= 'a' && article[index] <= 'z')) {
            word[wordlength] = article[index];
            wordlength++;
            index++;
        }
        word[wordlength+1] = '\0';
        // word[] = the word I want to compare to the dictionary

        if (wordlength >= 2){
            // when any other char than letter is in current letter, call isInDictionary function.

            isInDictionary(word, wordlength, words, &wordsi, dictionary);
            if (words[0] != '\0'){
                printf("%s \n", words);
            }
            for (int i = 0; i < articleSize; i++) {
                words[i] = '\0';
            }
            for (int i = 0; i < sizeof(word); i++) {
                word[i] = '\0';
            }
            index++;
            wordlength = 0;
        } else{
            for (int i = 0; i < sizeof(word); i++) {
                word[i] = '\0';
            }
            index++;
            wordlength = 0;
        }
    }
}

