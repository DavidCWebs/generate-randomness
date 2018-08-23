#include <stdio.h>
#include "random.h"
#include "base64.h"
#include "userInput.h"

int main(void)
{

    int len;
    getLength(&len);
    printf("len is %d\n", len);

    unsigned char *printableRandomChars = malloc(len);
    // unsigned char printableRandomChars[10];
    // generateRandom(printableRandomChars, 32, PRINTABLE);
    generateRandom(printableRandomChars, len, PRINTABLE);
    printf("generateRandomPrintable = %s\n", printableRandomChars);

    unsigned char randomChars[32];
    generateRandom(randomChars, 32, ALL_CHARS);

    size_t b64BufferLength = lenCharsBase64(sizeof(randomChars));
    unsigned char *b64Buffer = malloc(b64BufferLength);

    base64Encode((unsigned char *)randomChars, b64Buffer, sizeof(randomChars));
    printf("base64 encoded:\n%s\n", b64Buffer);
    free(b64Buffer);
    free(printableRandomChars);

    return 0;
}
