#include <stdio.h>
#include <limits.h>

int main(void)
{
    int max = INT_MIN;
    int n;
    int num;
    int cnt = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (max < num) {
            cnt = 1;
            max = num;
        } else if (max == num) {
            cnt += 1;
        }
    }
    printf("%d\n", cnt);
}