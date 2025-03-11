#include <stdio.h>
#include <math.h>

unsigned f(unsigned x)
{
    long long s = 0;
    unsigned i;
    for (i = 0; s <= x; i++) {
        s += 2 * i + 1;
    }
    return x * (i - 1);
}

unsigned g(long long x)
{
    long long k = cbrtl(x);
    return (x / k);
}

int main(void)
{
    unsigned x;
    scanf("%u", &x);
    printf("%u\n", g(x));
    return 0;
}