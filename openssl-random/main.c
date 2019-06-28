#include <stdio.h>
#include "random.h"
#include "lib/r64/base64.h"

enum mode {
    UNRESTRICTED,
    PRINTABLE
};

int main()
{
    if (RAND_status() == 0) {
        puts("The PRNG has not been seeded with enough data. Please try again later.");
        return 1;
    }

    __attribute__((unused)) const RAND_METHOD *meth = RAND_get_rand_method();

    // Size of random bytes
    const size_t COUNT = 32;

    char input[BUFSIZ];
    size_t numBytes;

    // See number reading FAQ
    printf ("Enter your number: ");
    if (fgets(input, sizeof(input), stdin) != NULL)
    {
        numBytes = atoi(input);
        printf ("You entered %lu\n", numBytes);
    }

    // Allow for dynamically allocated memory, variable random Bytes
    unsigned char *pureBytes = malloc(numBytes);
    setRandomBytes(&pureBytes, numBytes, UNRESTRICTED);
    unsigned char *b64Buffer = malloc(lenCharsBase64(numBytes));
    base64Encode(pureBytes, b64Buffer, numBytes);
    printf("r64:\n%s\n", b64Buffer);
    free(pureBytes);
    free(b64Buffer);

    // Limit to printable characters
    // -------------------------------------------------------------------------
    unsigned char *randomPrintableChars = malloc(numBytes);
    randomPrintable(&randomPrintableChars, numBytes);
    printf("randomPrintable():\n%s\n", randomPrintableChars);
    free(randomPrintableChars);

    // Generate hex string from random printable bytes
    // -------------------------------------------------------------------------
    unsigned char randomHexBytes[COUNT];
    unsigned char *pRandomHexBytes = randomHexBytes;
    setRandomBytes(&pRandomHexBytes, 32, PRINTABLE);
    printf("setRandomBytes, printable:\n%s\n", randomHexBytes);


    // Same char sequence expressed as a hex string
    // -------------------------------------------------------------------------
    char hexPrintableString[66];
    char *pHexPrintableString = hexPrintableString;
    bytesToHexString(randomHexBytes, &pHexPrintableString, COUNT);
    printf("Same as above, but chars expressed as a hex string:\n%s\n", hexPrintableString);

    // Non-printable characters as a hex string
    // -------------------------------------------------------------------------
    unsigned char randomBytes[COUNT];
    unsigned char *pRandomBytes = randomBytes;
    setRandomBytes(&pRandomBytes, 32, UNRESTRICTED);
    char hexString[66];
    char *pHexString = hexString;
    bytesToHexString(randomBytes, &pHexString, COUNT);
    printf("Random bytes, not restricted to printable, as a hex string:\n%s\n", hexString);

    return 0;
}
