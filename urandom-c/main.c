#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>
#include "../lib/r64/base64.h"
#include "../lib/integer-input.h"

void printInts(uint8_t *bytes, int n);

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
	// by printable ASCII characters. To print them to stdout, we can cast them to ints:
//	for (int i = 0; i < numBytes; i++) {
//		printf("%d\n", (int)pureBytes[i]);
//	}
//	printf("\n");
	printInts(pureBytes, numBytes);

	// You could also print bytes to stdout as hex characters:
	printf("pureBytes printed in hexadecimal format\n");
	for (int i = 0; i < numBytes; ++i) {
		printf("%02X", pureBytes[i]);
	}
	printf("\n");
	
	// If printable characters are needed (e.g. for a password) converting the uint8_ts
	// to a string of chars that are base 64 encoded is a good option:
	uint8_t *b64Buffer = malloc(lenCharsBase64(numBytes));
	base64Encode(pureBytes, b64Buffer, numBytes);
	printf("pureBytes as a radix 64 string:\n%s\n", b64Buffer);
	
	free(pureBytes);
	free(b64Buffer);

	return 0;
}

void printInts(uint8_t *bytes, int n)
{
	printf("Bytes printed as ints.\n");
	printf("[ ");
	for (int i = 0; i < n; ++i) {
		printf(i > 0 ? ", %d" : "%d", (int)*(bytes + i));
	}
	printf(" ]\n");
}
