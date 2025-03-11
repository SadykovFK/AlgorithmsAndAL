#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n, num;
    int max = INT_MIN; 
    int min = INT_MAX;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (min > num) {
            min = num;
        }

        if (max < num) {
            max = num;
        }
    }
    printf("%d\n", max - min);
    return 0;
}