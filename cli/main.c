#include "crypto/crypto.h"
#include "crypto/cryptoTest.h"

#define RUN_UNIT_TESTS 1

int main() 
{
    char * text = "Hello this text is a sample.\n<Html></Html> | ahahah | 90x873474 | >< )\n\\---------------------------";

    if (RUN_UNIT_TESTS)
    {
        cryptoTest();
    }
    else
    {
        printf("The string to be encrypted is:\n %s\n\n", text);
        text = encrypt(text, 1);
        printf("Encrypted:\n %s\n\n", text);
        text = decrypt(text, 1);
        printf("Decrypted:\n %s\n\n", text);
    }
    
    return 0;
}
