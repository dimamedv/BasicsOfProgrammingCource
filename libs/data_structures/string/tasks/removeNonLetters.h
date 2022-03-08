#ifndef BASICSOFPROGRAMMINGCOURSE_REMOVENONLETTERS_H
#define BASICSOFPROGRAMMINGCOURSE_REMOVENONLETTERS_H

#include "../string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_noNonLetters() {
    char s[] = "testWords";
    removeNonLetters(s);
    ASSERT_STRING("testWords", s);
}

void test_removeNonLetters_nonLettersEnd() {
    char s[] = "testWords   ";
    removeNonLetters(s);
    ASSERT_STRING("testWords", s);
}

void test_removeNonLetters_nonLettersStart() {
    char s[] = "    testWords";
    removeNonLetters(s);
    ASSERT_STRING("testWords", s);
}

void test_removeNonLetters_nonLettersInWord() {
    char s[] = "test   Words";
    removeNonLetters(s);
    ASSERT_STRING("testWords", s);
}

void test_removeNonLetters_emptyString() {
    char s[] = "";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}


void test_removeNonLetters_allNonLetters() {
    char s[] = "    ";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters() {
    test_removeNonLetters_allNonLetters();
    test_removeNonLetters_emptyString();
    test_removeNonLetters_noNonLetters();
    test_removeNonLetters_nonLettersEnd();
    test_removeNonLetters_nonLettersInWord();
    test_removeNonLetters_nonLettersStart();
}

#endif //BASICSOFPROGRAMMINGCOURSE_REMOVENONLETTERS_H
