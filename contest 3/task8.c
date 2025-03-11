#include <stdio.h>

int max_of_2(int fst, int scnd)
{
    if (fst > scnd) {
        return fst;
    } else {
        return scnd;
    }
}

int min_of_2(int fst, int scnd)
{
    if (fst > scnd) {
        return scnd;
    } else {
        return fst;
    }
}

int max_of_3(int fst, int scnd, int thrd)
{
    int prel = max_of_2(scnd, thrd);
    return max_of_2(fst, prel);
}

int min_of_3(int fst, int scnd, int thrd)
{
    int prel = min_of_2(scnd, thrd);
    return min_of_2(fst, prel);
}

int median(int fst, int scnd, int thrd) 
{
    int res;
    res = fst + scnd + thrd - min_of_3(fst, scnd, thrd) - max_of_3(fst, scnd, thrd);
    return res;
}


int main(void)
{
    int n;
    scanf("%d", &n);
    int arr_m[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr_m[i]);
    }

    for (int i = 0; i < (n / 2); i++) {
        for (int j = 0; j < (n - 2); j++) {
            arr_m[j] = median(arr_m[j], arr_m[j + 1], arr_m[j + 2]);
        }
    }
    printf("%d \n", arr_m[0]);
    return 0;
}