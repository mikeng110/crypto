#include "cryptoTest.h"

void cryptoTest()
{
    printf("cryptoTest =======================\n");
    modTest();
    setAlphabetCaseTest();
    shiftCharacterTest();
    encryptTest();
    decryptTest();
    printf("==================================\n");
}

void encryptTest()
{
    assert(
        strcmp(encrypt("abc", 1), "bcd") == 0 && "Expected abc -> bcd"
    );
    assert(
        strcmp(encrypt("xyz", 1), "yza") == 0 && "Expected xyz -> yza"
    );

    assert(
        strcmp(encrypt("xyz a", 1), "yza b") == 0 && "Expected xyz a -> yza b"
    );
    assert(
        strcmp(encrypt("<abc> !90", 1), "<bcd> !90") == 0 && "Expected <abc> !90 -> <bcd> !90"
    );

    printf("\tencryptTest - Passed\n");  
}

void decryptTest()
{
    assert(
        strcmp(decrypt("bcd", 1), "abc") == 0 && "Expected bcd -> abc"
    );
    assert(
        strcmp(decrypt("yza", 1), "xyz") == 0 && "Expected yza -> xyz"
    );
    assert(
        strcmp(decrypt("yza b", 1), "xyz a") == 0 && "Expected yza b -> xyz a"
    );
    assert(
        strcmp(decrypt("<bcd> !90", 1), "<abc> !90") == 0 && "Expected <bcd> !90 -> <abc> !90"
    );

    printf("\tdecryptTest - Passed\n");
}

int modTest()
{
    assert(mod(1,2) == 1);
    assert(mod(2,2) == 0);
    assert(mod(3,2) == 1);
    assert(mod(-1,3) == 2);
    assert(mod(-2,3) == 1);
    assert(mod(-3,3) == 0);

    printf("\tmodTest - Passed\n");
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

    setAlphabetCase(' ', &first_letter, &last_letter);
    assert(first_letter == '\0' && last_letter == '\0');

    setAlphabetCase('!', &first_letter, &last_letter);
    assert(first_letter == '\0' && last_letter == '\0');

    printf("\tsetAlpabetCaseTest - Passed\n");
}

void shiftCharacterTest()
{
    assert(shiftCharacter('a', 1) == 'b' &&  "expected a -> b, TEST CASE 1"); 
    assert(shiftCharacter('a', -1) == 'z' && "expected a -> z, TEST CASE 2 ");
    assert(shiftCharacter('z', 1) == 'a' &&  "expected z -> a, TEST CASE 3");
    assert(shiftCharacter('z', -1) == 'y' && "expected z -> b, TEST CASE 4");
    assert(shiftCharacter('a', 25) == 'z' && "expected a -> z, TEST CASE 5");
    
    printf("\tshiftCharacterTest - Passed\n");
}
