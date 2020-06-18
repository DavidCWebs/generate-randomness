#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>

typedef enum { INT, HEX } PrintMode;

void printBytes(uint8_t *bytes, int n, PrintMode mode);
void printInts(uint8_t *bytes, int n);
void printHex(uint8_t *bytes, int n);
void charsToHexString(char *hexString, const uint8_t *bytes, size_t n);

void printHex(uint8_t *bytes, int n)
{
	printBytes(bytes, n, HEX);
}

void printInts(uint8_t *bytes, int n)
{
	printBytes(bytes, n, INT);
}

void printBytes(uint8_t *bytes, int n, PrintMode mode)
{
	printf("[ ");
	for (int i = 0; i < n; ++i) {
		if (mode == INT) {
			printf(i > 0 ? ", %d" : "%d", (int)*(bytes + i));
		} else {
			printf(i > 0 ? ", %02x" : "%02x", *(bytes + i));
		}
	}
	printf(" ]\n");
}

void charsToHexString(char *hexString, const uint8_t *bytes, size_t n)
{
	char *lookup = "0123456789abcdef";
	for (size_t i = 0, j = 0; j < n; i = i + 2, ++j) {
		const uint8_t byte = *(bytes + j);
		uint8_t sixteens = (byte & 0xf0) >> 4;
		uint8_t units = byte & 0x0f;
		*(hexString + i) = lookup[sixteens];
		*(hexString + i + 1) = lookup[units];
	}
	*(hexString + (2 * n)) = '\0';
}
#endif
