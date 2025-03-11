#include <stdio.h>
#include <string.h>

int min_of_2(int a, int b)
{
    if (a > b) return b;
    return a;
}

void z_func(int *z, char *line)
{
    int n = strlen(line);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min_of_2(r - i + 1, z[i - l]);
        }

        while ((i + z[i] < n) && (line[z[i]] == line[i + z[i]])) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

int main(void)
{
    char line[1000002];
    fgets(line, 1000002, stdin);
    line[strcspn(line, "\n")] = 0;

    int length = strlen(line);
    int z[1000002];
    
    z[0] = 0;
    z_func(z, line);

    z[0] = length;

    short flag;
    for (int t = 1; t <= length; t++) {
        flag = 1;
        for (int d = 0; ((d + 1) * t) < length; d++) {
            if (z[d * t] - z[(d + 1) * t] != t) {
                flag = 0;
            }    
        }

        if (flag) {
            printf("%d ", t);
        }    
    }

    printf("\n");
    return 0;
}