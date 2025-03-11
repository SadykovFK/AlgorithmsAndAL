#include <stdio.h>

int main(void) 
{    
    int n, m;
    scanf("%d", &n);
    int arr_a[n];
 
    for (int i = 0; i < n; i++) {
        int number;
        scanf("%d", &number);
        arr_a[i] = number;
    }
    
    scanf("%d", &m);
    int arr_x[m];

    for (int i = 0; i < m; i++) {
        int number;
        scanf("%d", &number);
        arr_x[i] = number;
    }

    for (int i = 0; i < m; i++) {
        int x = 1;
        int total = 0;
        for (int j = 0; j < n; j++) {
            total += arr_a[j] * x;
            x *= arr_x[m - i - 1];
        }

        printf("%d ", total);
    }
    
    return 0;
}