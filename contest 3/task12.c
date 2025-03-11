#include <stdio.h>

int sacrifice(int set_1, int set_2, int n, int array[])
{
    int sum_1 = 0, sum_2 = 0;
    for (int i = 0; i < n; i++) {
        if (set_1 & (1 << i)) sum_1 += array[i];
        if (set_2 & (1 << i)) sum_2 += array[i];
    }

    if (sum_1 == sum_2) return sum_1;
    else return 0;
}

int main(void)
{
    int n;
    int max_sum = 0;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    for (int subs_1 = 1; subs_1 < (1 << n); subs_1++) {
        for (int subs_2 = 1; subs_2 < (1 << n); subs_2++) {
            if ((subs_2 & subs_1) == 0) {
                int res;
                res = sacrifice(subs_1, subs_2, n, array);
                if (res > max_sum) max_sum = res;
            }
        }
    }

    printf("%d\n", max_sum);
    return 0;
}