#include <stdio.h>

int main(void)
{
    int n;
    int size;
    int fst_row[10001], scnd_row[10001];
    int total = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &size);
        fst_row[i] = size;  
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &size);
        scnd_row[i] = size;  
    }

    for (int i = 0; i < n; i++) {
        int cur_fst = fst_row[i], cur_scnd = scnd_row[i];
        if (cur_fst > cur_scnd) {
            total += cur_fst;
        } else {
            total += cur_scnd;
        }
    }

    printf("%d \n", total);
    return 0;
}