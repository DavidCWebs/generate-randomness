#ifndef RANDOM_H
#define RANDOM_H

#include <openssl/rand.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "lib/r64/base64.h"

int randomPrintable(unsigned char **isprintBuf, size_t n);
int randomHexString(size_t n);
int setRandomBytes(unsigned char **bytesBuffer, size_t n, int mode);
int bytesToHexString(const unsigned char *bytesBuffer, char **hexString, size_t n);

#endif
