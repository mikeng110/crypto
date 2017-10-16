#include "crypto.h"

char * encrypt(char * text, int key)
{
    int i;
    char encryptedText[STRING_MAX_LENGTH];
    char *s_ptr = encryptedText;

    strcpy(encryptedText, text);

    for (i = 0; text[i] != '\0'; i++ )
    {
        encryptedText[i] = shiftLetter(text[i], key);
    }

    return s_ptr;
}

char * decrypt(char * text, int key)
{
    return encrypt(text, -1*key);
}

void setAlphabetCase(char letter, char *first_letter, char *last_letter)
{
    if (isalpha(letter))
    {
        if (isupper(letter))
        { 
            *first_letter = FIRST_LETTER_UPPER;
            *last_letter = LAST_LETTER_UPPER;
        }
        else
        {
            *first_letter = FIRST_LETTER_LOWER;
            *last_letter = LAST_LETTER_LOWER;
        }
    }
    else
    {
        *first_letter = '\0';
        *last_letter = '\0';
    }
}

int mod(int a, int b)
{
    int result;
    result = a % b;
    while (result < 0)
    {
        result += b;
    }
    return result;
}

char shiftLetter(char letter, int offset)
{
    char first_letter, last_letter;
    int dist, dist_total, letter_pos;

    if (isdigit(letter))    return letter; 
    if (offset == 0)        return letter;

    setAlphabetCase(letter, &first_letter, &last_letter);
   
    dist = letter - first_letter;
    dist_total = last_letter - first_letter;
    letter_pos = mod(dist + offset, dist_total+1);

    return  first_letter + letter_pos;

}