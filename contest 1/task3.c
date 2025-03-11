#include <stdio.h>
#include <ctype.h>

int main(void) 
{
    int n;
    char symb;
    scanf("%d", &n);
    while ((symb = getchar()) != '.') {
        if (isalpha(symb) && islower(symb)) {
            symb = (symb - 'a' + n) % 26 + 'a'; 
        } else if (isalpha(symb) && isupper(symb)) {
            symb = (symb - 'A' + n) % 26 + 'A';
        }
        putchar(symb);
    }
    putchar('.');
    return 0;
}