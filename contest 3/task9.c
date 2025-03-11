#include <stdio.h>
#include <math.h>

void intersection_coord(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double length_1, length_2;
    double vec_1x, vec_1y, vec_2x, vec_2y;
    double inter_x, inter_y;
    vec_1x = fabs(x1 - x2);
    vec_1y = fabs(y1 - y2);
    vec_2x = fabs(x1 - x3);
    vec_2y = fabs(y1 - y3);
    length_1 = sqrt(pow(vec_1x, 2) + pow(vec_1y, 2));
    length_2 = sqrt(pow(vec_2x, 2) + pow(vec_2y, 2));
    inter_x = (length_2 * x2 + length_1 * x3) / (length_1 + length_2);
    inter_y = (length_2 * y2 + length_1 * y3) / (length_1 + length_2);
    printf("%.5lf %.5lf \n", inter_x, inter_y);
}

int main(void)
{
    double ax, ay, bx, by, cx, cy;
    scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy);
    intersection_coord(cx, cy, bx, by, ax, ay);
    intersection_coord(ax, ay, bx, by, cx, cy);
    intersection_coord(bx, by, cx, cy, ax, ay);
    return 0;
}