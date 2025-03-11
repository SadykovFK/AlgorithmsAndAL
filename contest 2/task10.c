#include <stdio.h>
#include <math.h>
#define EPSILON 1e-9

int main(void)
{
    int n;
    scanf("%d", &n);
    double array_s[n];
    double array_a[n];
    double v0 = 0;
    double time = 0;
    double total_time = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%lf", &array_s[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%lf", &array_a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (fabs(array_a[i]) < EPSILON) {
            time = array_s[i] / v0;
            total_time += time;
        } else {
            time = (-v0 + sqrt(v0 * v0 + 2 * array_a[i] * array_s[i])) / array_a[i];
            total_time += time;
            v0 += array_a[i] * time;
        }
    }
    printf("%.4lf \n", total_time);

    return 0;
}