#include <math.h>
#include <stdio.h>

size_t lenCharsBase64(size_t inputLength);
void base64Encode(unsigned char const *inputBuffer, unsigned char *b64Buffer, size_t inputLength);
