#include <stdio.h>

int main(void)
{
    int n;
    int array[10001];
    int cnt = 1;

    scanf("%d", &n);
    while (n != 0) {
        array[cnt] = n;
        cnt++;
        scanf("%d", &n);
    }

    for (int i = 1; i < cnt; i++) {
        printf("%d ", array[cnt - i]);
    }

    return 0;
}