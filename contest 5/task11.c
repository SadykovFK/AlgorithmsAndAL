#include <stdio.h>

unsigned long max_of_2(unsigned long a, unsigned long b)
{
    if (a > b) return a;
    return b;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    unsigned long roads[n][m];
    unsigned long results[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lu", &roads[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        results[i][0] = roads[i][0];
    }

    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            unsigned long prev_max_road = results[i][j - 1];
            if (i != 0) { 
                prev_max_road = max_of_2(prev_max_road, results[i - 1][j - 1]);
            }
            if (i != (n - 1)) {
                prev_max_road = max_of_2(prev_max_road, results[i + 1][j - 1]);
            }
            results[i][j] = roads[i][j] + prev_max_road;
        }
    }

    unsigned long max_expanses = 0;

    for (int i = 0; i < n; i++) {
        max_expanses = max_of_2(max_expanses, results[i][m - 1]);
    }

    printf("%lu\n", max_expanses);
    return 0;
}