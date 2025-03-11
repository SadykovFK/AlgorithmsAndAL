#include <stdio.h>

int main(void)
{
    int hex_n, t_hex_n = 0;
    scanf("%x", &hex_n);
    for (int i = 0; i < 16; i++)
    {
        int k, l;
        k = i / 4;
        l = i % 4;
        if (hex_n & (1 << i))
        {
            t_hex_n += (1 << (4 * l + k)); 
        }
    }
    printf("%04x", t_hex_n); 
    return 0;
}