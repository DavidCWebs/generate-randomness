#include "userInput.h"

void setLength(size_t *len, size_t max)
{
    printf("Please enter a number that is less than %lu\n", max);
    int sign = 1;
    char ch;
    int j = 0;
    ch = getchar();
    if((ch == '-') || (ch == '+')) {
        sign = (ch == '-') ? -1 : 1;
    } else {
        if (ch >= '0' && ch <= '9') {
            j *= 10;
            j += ch - '0';
        }
    }
    while ((ch = getchar()) != '\n')
    {
        if (ch > '9' || ch < '0')
            continue; // or print an error and exit
        j *= 10;
        j += ch - '0';
    }
    j *= sign;
    *len = j;
    if (j > max) {
        printf("That number is too large you muppet! Less than %lu please.\n", max);
        setLength(len, max);
    }
}
