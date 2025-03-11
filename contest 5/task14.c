#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int number)
{
    if (number == 2) return true;

    for (int i = 2; i < sqrt(number) + 1; i++) {
        if (number % i == 0) return false;
    }
    
    return true;
}

void hyperPrime(int current_num, int length, int nLength)
{
    if (length == nLength) {
        printf("%d ", current_num);
    } else {
        int new_num = 0;

        for (int i = 1; i < 10; i++) {
            new_num = current_num * 10 + i;
            if (isPrime(new_num)) {
                hyperPrime(new_num, length + 1, nLength);
            }
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 2; i < 10; i++) {
        if (isPrime(i)) {
            hyperPrime(i, 1, n);
        }
    }

    printf("\n");
    return 0;
}