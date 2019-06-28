#include "random.h"

int setRandomBytes(unsigned char **bytesBuffer, size_t n, int mode)
{
    if (mode == 0) {
        while (!RAND_bytes(*bytesBuffer, sizeof(unsigned char) * n)) ;
        return 0;
    }
    randomPrintable(bytesBuffer, n);
    return 0;
}

int randomPrintable(unsigned char **isprintBuf, size_t n)
{
    size_t i;
    unsigned char buf[1];
    for (i = 0; i < n; i++) {
        while (RAND_bytes(buf, sizeof(char))) {
            if (isprint(buf[0])) {
                break;
            }
        }
        memcpy((*isprintBuf + i), &buf, sizeof(char));
    }
    buf[0] = '\0';
    memcpy((*isprintBuf + i), &buf, sizeof(char));
    return 0;
}

int randomHexString(size_t n)
{
    char hexStringBuf[2];
    char hexString[66];
    size_t i;
    unsigned char buf[1];

    for (i = 0; i < n; i++) {
        while (!RAND_bytes(buf, sizeof(char))) ;
        sprintf(hexStringBuf, "%02x", buf[0]);
        strncat(hexString, hexStringBuf, sizeof(hexStringBuf));
    }
    strncat(hexString, "\0", sizeof(char));
    printf("Hex String Key: \n%s\n", hexString);

    return 0;
}

int bytesToHexString(const unsigned char *bytesBuffer, char **hexString, size_t n)
{
    char buf[2];
    for (size_t i = 0; i < n; i++) {
        sprintf(buf, "%02x", bytesBuffer[i]);
        strncat(*hexString, buf, sizeof(buf));
    }
    strncat(*hexString, "\0", sizeof(char));
    return 0;
}
