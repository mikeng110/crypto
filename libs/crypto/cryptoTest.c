#include "cryptoTest.h"

void encryptTest()
{
    assert(
        strcmp(encrypt("abc", 1), "bcd") == 0 && "Expected abc -> bcd"
    );
    assert(
        strcmp(encrypt("xyz", 1), "yza") == 0 && "Expected xyz -> yza"
    );

    printf("encryptTest - Passed\n");  
}

void decryptTest()
{
    assert(
        strcmp(decrypt("bcd", 1), "abc") == 0 && "Expected bcd -> abc"
    );
    assert(
        strcmp(decrypt("yza", 1), "xyz") == 0 && "Expected yza -> xyz"
    );

    printf("decryptTest - Passed\n");
}

void setAlphabetCaseTest()
{
    char first_letter, last_letter;

    setAlphabetCase('a', &first_letter, &last_letter);
    assert(first_letter == FIRST_LETTER_LOWER && last_letter == LAST_LETTER_LOWER);

    setAlphabetCase('A', &first_letter, &last_letter);
    assert(first_letter == FIRST_LETTER_UPPER && last_letter == LAST_LETTER_UPPER);

    setAlphabetCase('0', &first_letter, &last_letter);
    assert(first_letter == '\0' && last_letter == '\0');

    printf("setAlpabetCaseTest - Passed\n");
}

void shiftLetterTest()
{
    assert(shiftLetter('a', 1) == 'b' &&  "expected a -> b, TEST CASE 1"); 
    assert(shiftLetter('a', -1) == 'z' && "expected a -> z, TEST CASE 2 ");
    assert(shiftLetter('z', 1) == 'a' &&  "expected z -> a, TEST CASE 3");
    assert(shiftLetter('z', -1) == 'y' && "expected z -> b, TEST CASE 4");
    assert(shiftLetter('a', 25) == 'z' && "expected a -> z, TEST CASE 5");
    
    printf("shiftLetterTest - Passed\n");
}
