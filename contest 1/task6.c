#include <stdio.h>

int main(void) {
    unsigned int number;
    int shift;
    scanf("%u %d", &number, &shift);
    printf("%u", number >> shift | number << (32 - shift));
    return  0;
}