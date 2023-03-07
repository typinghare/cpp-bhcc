/**
 * @author James (Zhuojian Chen)
 * @date Feb 23rd, 2022
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string.h>

using namespace std;

char *readFile(string filepath);

int countSentence(char *str);

int countWords(char *str);

int printCapitalizedWords(char *str, ostream &os);

int countWords(char *str, string word);

int main() {
    const string FILEPATH = "../resource/TaleOfTwoCities.txt";
//    const string FILEPATH = "TaleOfTwoCities.txt";

    char *cstr = readFile(FILEPATH);
    if (cstr == nullptr) return 0;

    const string wordToFind = "was";
    int numSentences = countSentence(cstr);
    int numWords = countWords(cstr);
    int numOfSpecifiedWord = countWords(cstr, wordToFind);

    cout << endl;
    cout << "There are " << numSentences << " sentences in the file." << endl;
    cout << "There are " << numWords << " words in the file." << endl;
    cout << "There are " << numOfSpecifiedWord << " \"" << wordToFind << "\" in the file." << endl;

    cout << endl;
    cout << "The capitalized words that are not at the beginning of sentences: " << endl;
    int numCapitalizedWords = printCapitalizedWords(cstr, cout);
    cout << "There are " << numCapitalizedWords << " words meet the requirement." << endl;
}

/**
 * Returns the number of sentences.
 * @return
 */
char *readFile(string filepath) {
    const string absolutePath = filesystem::absolute(filepath);
    cout << "Reading File: " << absolutePath << endl;
    if (!filesystem::exists(absolutePath)) {
        cout << "File does not exist: " << absolutePath << endl;
        return nullptr;
    }

    ifstream fileInputStream(filepath);
    stringstream ss;
    string line;
    while (getline(fileInputStream, line)) {
        ss << line << endl;
    }

    std::string str = ss.str();
    char *cstr = new char[str.length() - 1];
    strcpy(cstr, str.c_str());

    return cstr;
}

/**
 * Returns the number of sentences in the given string.
 * We assume that a dot character followed by space character is considered as a period.
 * In particular, if a period is preceded by "Mr", "Mrs" or "Miss", then it is not considered
 * as a period.
 * @param str the string to process
 * @return the number of sentences in the string.
 */
int countSentence(char *str) {
    int count = 0;  // the number of sentences
    bool sentenceEnded = false;
    stringstream curr;  // the word that is being scanned

    for (const char *p = str; *p; ++p) {
        const char c = *p;
        if (isspace(c)) {
            if (sentenceEnded) {
                count++;
                sentenceEnded = false;
            }
            curr.str(string());
        } else if (c == '.' || c == '?' || c == '!') {
            const string curr_str = curr.str();
            if (c == '.' && (curr_str == "Mr" || curr_str == "Mrs" || curr_str == "Miss"))
                curr << c;
            else sentenceEnded = true;
        } else if (isalpha(c)) {
            curr << c;
        }
    }

    if (sentenceEnded) count++;

    return count;
}

/**
 * Returns the number of words in the given string.
 * @param str the string to process
 * @return the number of words in the string.
 */
int countWords(char *str) {
    int count = 0; // the number of words
    stringstream curr; // the word that is being scanned

    for (const char *p = str; *p; ++p) {
        const char c = *p;
        // static_cast<char>(0x2014) == '—' (em-dash, 破折号)
        if (isspace(c) || c == static_cast<char>(0x2014)) {
            if (curr.str().length() != 0) {
                count++;
                curr.str(string());
            }
        } else if (isalpha(c) || c == '-') {
            curr << c;
        }
    }

    return count;
}

/**
 * Prints all capitalized words in the given string.
 * The words at the beginning of the sentences do not count.
 * @param str the string to process
 * @param os out stream
 * @return the number of capitalized words in the string.
 */
int printCapitalizedWords(char *str, ostream &os) {
    int count = 0; // the number of capitalized words
    stringstream curr;  // the word that is being scanned
    bool sentenceStarted = true;

    for (const char *p = str; *p; ++p) {
        const char c = *p;
        if (isalpha(c) || c == '-') {
            curr << c;
        } else {
            if (curr.str().length() == 0) continue;

            bool toSetSentenceStarted = false;
            if (isspace(c) || c == static_cast<char>(0x2014)) {
                toSetSentenceStarted = true;
            } else if (c == '.' || c == '?' || c == '!') {
                const string curr_str = curr.str();
                if (c == '.' && (curr_str == "Mr" || curr_str == "Mrs" || curr_str == "Miss")) {}
                else sentenceStarted = true;
            }

            // A-Z starts with "010", while a-z starts with "011"
            if (!sentenceStarted && (curr.peek() & 0b00100000) == 0) {
                count++;
                os << curr.str() << endl;
            }
            curr.str(string());
            if (toSetSentenceStarted) sentenceStarted = false;
        }
    }

    return count;
}

/**
 * Counts and returns the number of occurrences of a particular word.
 * @param str the string to process
 * @param word the word to search for
 * @return the number of occurrences of a particular word.
 */
int countWords(char *str, string word) {
    int count = 0;
    stringstream curr;

    for (const char *p = str; *p; ++p) {
        const char c = *p;
        if (isspace(c) || c == static_cast<char>(0x2014)) {
            const string curr_str = curr.str();
            if (curr_str == word) count++;

            curr.str(string());
        } else if (isalpha(c)) {
            curr << c;
        }
    }

    return count;
}