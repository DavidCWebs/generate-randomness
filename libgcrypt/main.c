#include <stdio.h>
#include "random.h"
#include "base64.h"
#include "userInput.h"

int main(void)
{

	size_t len;
	setLength(&len, 255);

	// Allow space for terminating nul
	unsigned char *printableRandomChars = malloc(len + 1);
	generateRandom(printableRandomChars, len, PRINTABLE);
	printf("generateRandomPrintable = %s\n", printableRandomChars);
	free(printableRandomChars);

	unsigned char *randomChars = malloc(len);
	size_t b64BufferLength = lenCharsBase64(len);
	unsigned char *b64Buffer = malloc(b64BufferLength);
	generateRandom(randomChars, len, ALL_CHARS);

	base64Encode((unsigned char *)randomChars, b64Buffer, len);
	printf("base64 encoded:\n%s\n", b64Buffer);
	free(b64Buffer);
	free(randomChars);

	return 0;
}
