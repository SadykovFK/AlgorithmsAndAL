#include <stdio.h>

void magic_reverse(int pos) 
{
    int number;
    scanf("%d", &number);
    if (number != 0) {
        if (pos % 2 != 0) {
            printf("%d ", number);
        }
        magic_reverse(pos + 1);
        if (pos % 2 == 0) {
            printf("%d ", number);
        }
    }
}

int main(void)
{
    magic_reverse(1);
    printf("\n");
    return 0;
}