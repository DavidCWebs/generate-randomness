#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "../lib/r64/base64.h"
#include "../lib/integer-input.h"

void setRandomBytesUrandom(unsigned char **bytesBuffer, size_t n)
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
	unsigned char *pureBytes = malloc(numBytes);
	setRandomBytesUrandom(&pureBytes, numBytes);
	
	// `pureBytes` is now a pointer to `numBytes` unsigned chars that have been
	// randomly drawn from /dev/urandom. Some of these bytes may not be representable
	// by printable ASCII characters. To print them to stdout, we can cast them to ints:
	for (int i = 0; i < numBytes; i++) {
		printf("%d\n", (int)pureBytes[i]);
	}
	printf("\n");

	// You could also print bytes to stdout as hex characters:
	printf("pureBytes printed in hexadecimal format\n");
	for (int i = 0; i < numBytes; ++i) {
		printf("%02X", pureBytes[i]);
	}
	printf("\n");
	
	// If printable characters are needed (e.g. for a password) converting the unsigned chars
	// to a string of chars that are base 64 encoded is a good option:
	unsigned char *b64Buffer = malloc(lenCharsBase64(numBytes));
	base64Encode(pureBytes, b64Buffer, numBytes);
	printf("pureBytes as a radix 64 string:\n%s\n", b64Buffer);
	
	free(pureBytes);
	free(b64Buffer);

	return 0;
}
