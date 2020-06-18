#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>
#include "../lib/r64/base64.h"
#include "../lib/integer-input.h"
#include "../lib/utilities.h"

void setRandomBytesUrandom(uint8_t **bytesBuffer, size_t n)
{
	int errnum;
	FILE *fp = fopen("/dev/urandom", "r");
	if (!fp) {
		errnum = errno;
		fprintf(stderr, "Error opening /dev/urandom. %s", strerror(errnum));
	}
	fread(*bytesBuffer, sizeof(**bytesBuffer), n, fp);
	fclose(fp);
}

int main()
{
	int numBytes = 0;
	puts("Enter the number of random bytes required:");
	intFromStdin(&numBytes);
	uint8_t *pureBytes = malloc(numBytes);
	setRandomBytesUrandom(&pureBytes, numBytes);
	// `pureBytes` is now a pointer to `numBytes` uint8_ts that have been
	// randomly drawn from /dev/urandom. Some of these bytes may not be representable
	// by printable ASCII characters. 
	
	// If printable characters are needed (e.g. for a password or random key) converting
	// the uint8_ts to a string of base 64 encoded characters is a good option:
	uint8_t *b64Buffer = malloc(lenCharsBase64(numBytes));
	base64Encode(pureBytes, b64Buffer, numBytes);
	printf("pureBytes as a radix 64 string:\n%s\n", b64Buffer);

	
	printInts(pureBytes, numBytes);
	printHex(pureBytes, numBytes);

	// You could also represent the bytes as a hexstring - in this case, a string of
	// zero padded hexadecimal characters, with each pair of characters representing
	// the numerical value of a byte.
	char *hexstring = calloc((numBytes * 2) + 1, sizeof(*hexstring)); 
	charsToHexString(hexstring, pureBytes, (size_t)numBytes);
	printf("Output a hexstring\n");
	printf("%s\n", hexstring);

	free(hexstring);
	free(pureBytes);
	free(b64Buffer);

	return 0;
}
