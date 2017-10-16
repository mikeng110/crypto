#include "crypto/crypto.h"
#include "crypto/cryptoTest.h"

#define RUN_UNIT_TESTS 1

int main() 
{

    char * text = "Apples90";

    if (RUN_UNIT_TESTS)
    {
        modTest();
        setAlphabetCaseTest();
        shiftLetterTest();
        encryptTest();
        decryptTest();
    }

    printf("The string to be encrypted is: %s\n", text);
    text = encrypt(text, 1);
    printf("Encrypted: %s\n", text);
    text = decrypt(text, 1);
    printf("Decrypted: %s\n", text);

    return 0;
}
