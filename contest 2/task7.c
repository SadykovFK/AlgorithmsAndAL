#include <stdio.h>

int main(void) {
    int n;
    signed int number;
    signed int array[10001];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%u", &number);
        array[i] = number;
    }

    for (int i = 0; i < n; i++) {
        if ((array[i] < 0) || (array[i] > n)) {
            printf("%s", "No\n");
            return 0;
        }
        for (int j = 0; j < i; j++) {
            if (array[j] == array[i]) {
                printf("%s", "No\n");
                return 0;
            }
        }
    }

    printf("%s", "Yes\n");
    return 0;
}