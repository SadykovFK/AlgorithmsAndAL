#include <stdio.h>

long double find_degree(double number, long long degree)
{   
    double res = 1;
    for (long long i = 0; i < degree; i++) 
    {
        res *= number;
    }
    return res;
}

long long factorial(long long fact_numb) 
{
    long long res = 1;
    for (long long i = 1; i < fact_numb + 1; i++) 
    {
        res *= i;
    }
    return res;
}

int main(void) 
{
    double x, result = 0;
    int n, j = 1;
    scanf("%lg %d", &x, &n);
    for (int i = 0; i < n; i++) 
    {
        result += find_degree(-1, i) * (find_degree(x, j) / factorial(j));
        j += 2;
    }
    printf("%.6lf", result);
    return 0;
}