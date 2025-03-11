#include <stdio.h>
#include <stdlib.h>

long long find_tray(long long **matrix, int m)
{
    long long tray = 0;
    
    for (int i = 0; i < m; i++) {
        tray += matrix[i][i];
    }

    return tray;
}

int main(void)
{
    long long max_tray = -1;
    int max_m = 0;
    int n;
    long long **max_matrix = malloc(sizeof(long long *));
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);

        long long **matrix = malloc(sizeof(long long *) * m);
        for (int i = 0; i < m; i++) {
            matrix[i] = malloc(sizeof(long long) * m);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%lld", &matrix[i][j]);
            }
        }

        long long tray = find_tray(matrix, m);

        if (max_tray < tray) {

            for (int i = 0; i < max_m; i++) {
                free(max_matrix[i]);
            }

            max_tray = tray;
            max_m = m;

            max_matrix = realloc(max_matrix, sizeof(long long *) * m);
            if (max_matrix == NULL) {
                free(max_matrix);
                return 241;
            }    
            for (int i = 0; i < m; i++) {
                max_matrix[i] = malloc(sizeof(long long) * m);
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    max_matrix[i][j] = matrix[i][j];
                }
            }
        }

        for (int i = 0; i < m; i++) {
            free(matrix[i]);
        }
        free(matrix);

    }

    for (int i = 0; i < max_m; i++) {
        for (int j = 0; j < max_m; j++) {
            printf("%lld ", max_matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < max_m; i++) {
        free(max_matrix[i]);
    }
    free(max_matrix);

    return 0;
}