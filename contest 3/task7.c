#include <stdio.h>
#include <stdlib.h>
#define EPSILON 1e-9

double max_of_2(double fst, double scnd)
{
    if ((fst - scnd) > EPSILON) {
        return fst;
    } else {
        return scnd;
    }
}

double triangle_area(int fst_x, int fst_y, int scnd_x, int scnd_y, int thrd_x, int thrd_y) 
{
    double res;
    res = abs(fst_x * (scnd_y - thrd_y) + scnd_x * (thrd_y - fst_y) + thrd_x * (fst_y - scnd_y));
    return res / 2.0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int points_arr[n][2];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points_arr[i][0], &points_arr[i][1]);
    }

    double max_area = 0.0;

    for (int i = 0; i < n; i++) {
        int xi, yi;
        xi = points_arr[i][0];
        yi = points_arr[i][1];
        for (int j = i + 1; j < n; j++) {
            int xj, yj;
            xj = points_arr[j][0];
            yj = points_arr[j][1];
            for (int k = j + 1; k < n; k++) {
                int xk, yk;
                double prel_res;
                xk = points_arr[k][0];
                yk = points_arr[k][1];
                prel_res = triangle_area(xi, yi, xj, yj, xk, yk);
                max_area = max_of_2(max_area, prel_res); 
            }
        }
    }
    printf("%.6lf \n", max_area);
    return 0;
}