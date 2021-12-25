#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;

const int SIZE = 1000;
const char allowed[] = " abcdefghijklmnopqrstuvwxyz";

void customSwap(char**, char**);
bool isBigger(char*, char*);
void sortList(char**, const int&);
void readString(char*);
void addNewWord(char**, int&, char*);
void addChar(char*, char);
int getStringSize(const char*);
bool isInString(const char*, char);

int main() {
    char s[SIZE] = "";

    readString(s);

    char** words = new char* [SIZE];
    for (int i = 0; i < SIZE; ++i) {
        words[i] = new char[SIZE] {};
    }

    int len = getStringSize(s), n = 0;
    char currentWord[SIZE] = "";
    for (int i = 0; i < len; ++i) {
        if (s[i] == ' ') {
            if (getStringSize(currentWord) != 0) {
                addNewWord(words, n, currentWord);
                currentWord[0] = '\0';
            }
        }
        else {
            addChar(currentWord, s[i]);
        }
    }

    sortList(words, n);

    for (int i = 0; i < n; ++i) {
        cout << words[i] << "\n";
    }

    for (int i = 0; i < n; ++i) {
        delete[] words[i];
    }
    delete[] words;

    return 0;
}




void customSwap(char** str1, char** str2) {
    char* temp = *str1;
    (*str1) = *str2;
    (*str2) = temp;
}

bool isBigger(char* str1, char* str2) {
    int p = 0;
    int minLen = min(getStringSize(str1), getStringSize(str2));

    while ((p < minLen) && (str1[p] == str2[p])) {
        ++p;
    }

    return (str1[p] > str2[p]);
}

void sortList(char** words, const int& n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; (j + 1) < n; ++j) {
            if (isBigger(words[j], words[j + 1])) {
                customSwap(&words[j], &words[j + 1]);
            }
        }
    }
}

bool isInString(const char* str, char c) {
    int len = getStringSize(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] == c) {
            return true;
        }
    }
    return false;
}

void readString(char* str) {
    cout << "Input string with english letters: ";
    while (true) {
        char c;
        c = _getch();

        if ((int)c == 13) {
            break;
        }

        if (!isInString(allowed, c)) {
            continue;
        }

        cout << c;
        addChar(str, c);
    }
    addChar(str, ' ');
    cout << "\n";
}

void addNewWord(char** a, int& n, char* str) {
    int lenStr = getStringSize(str);
    for (int i = 0; i < lenStr; ++i) {
        a[n][i] = str[i];
    }
    ++n;
}

int getStringSize(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

void addChar(char* str, char c) {
    int len = getStringSize(str);
    str[len] = c;
    str[len + 1] = '\0';
}
