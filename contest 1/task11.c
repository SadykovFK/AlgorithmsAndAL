#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t num, young, old;
    scanf("%u", &num);
    young = ~num & 0xff000000;
    old = num & 0x00ffffff;
    num = young | old;
    printf("%u\n", num);
    return 0;
}