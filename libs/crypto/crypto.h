#ifndef CRYPTO_H_
#define CRYPTO_H_

#define FIRST_LETTER_LOWER  'a'
#define LAST_LETTER_LOWER   'z'
#define FIRST_LETTER_UPPER  'A'
#define LAST_LETTER_UPPER   'Z'

#define STRING_MAX_LENGTH   5000

#include <ctype.h>
#include <string.h>

char * encrypt(char * text, int key);
char * decrypt(char * text, int key);
void setAlphabetCase(char letter, char *first_letter, char *last_letter);
char shiftLetter(char letter, int offset);

#endif