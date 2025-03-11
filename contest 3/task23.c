#include <stdio.h>

int main(void)
{
    int m;
    scanf("%d", &m);

    int new_array[m][3];
    int array[m][3];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &array[i][0], &array[i][1]);
        array[i][3] = array[i][0] * array[i][1];
    }
    int k = 0;
    for (int i = 1; i < 200; i++) {
        for (int j = 0; j < m; j++) {
            if (i == array[j][0]) {
                new_array[k][0] = array[j][0];
                new_array[k][1] = array[j][1];
                k++;    
            }
        }
    }
    int prev_size = 0;
    int blocks = 1;
    for (int i = 0; i < m; i++) {
        int numb = new_array[i][0];
        int size = new_array[i][1];
        if ((blocks == numb) && (size * blocks > prev_size)) {
            prev_size = size;
            blocks++;
        } else {
            printf("%s", "No\n");
            return 0;
        }
    }
    printf("%s", "Yes\n");
    return 0;
}


