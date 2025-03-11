#include <stdio.h>

int main(void)
{
    int n;
    int fst_num = 0, scnd_num = 0;
    scanf("%d", &n);
    int array[n];
    int all_xor = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++) {
        all_xor ^= array[i];
    }

    int bit = all_xor & -all_xor;

    for (int i = 0; i < n; i++) {
        if (array[i] & bit) {
            fst_num ^= array[i];
        } else {
            scnd_num ^= array[i];
        }
    }

    if (fst_num > scnd_num) {
        printf("%d %d", scnd_num, fst_num);
    } else {
        printf("%d %d", fst_num, scnd_num);
    }
    return 0;
}