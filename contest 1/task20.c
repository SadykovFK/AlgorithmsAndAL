#include <stdio.h>

int main(void)
{
    double a;
    double b;
    double c;
    double d;
    double epsilon = 0.000001;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    if (a < b)
    {
        double temp;
        temp = a;
        a = b;
        b = temp;
    }
    if (c < d)
    {
        double temp;
        temp = c;
        c = d;
        d = temp;
    }
    if ((((a - c) < -epsilon) && ((b - d) < -epsilon)) ||
    (((c - a) < -epsilon) && ((b - d) < -epsilon)))
    {
        printf("%s", "NO\n");
        return 0;
    }
    if ((c <= a) && (d <= b)) 
    {
        printf("%s", "YES\n");
        return 0;
    }
    if ((c > a) && (d <= b))
    {
        double fst_expr;
        double scnd_expr;
        fst_expr = ((a + b) / (c + d)) * ((a + b) / (c + d));
        scnd_expr = ((a - b) / (c - d)) * ((a - b) / (c - d));
        if ((fst_expr + scnd_expr) >= (2 - epsilon))
        {
            printf("%s", "YES\n");
            return 0;
        }
    }
    printf("%s", "NO\n");
    return 0;
}