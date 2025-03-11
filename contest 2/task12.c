#include <stdio.h>
#define MAX(A, B) (A > B ? A : B)
#define MIN(A, B) (A < B ? A : B)

int main(void)
{
    int cube_arr[16];
    int max_number = 0;
    int max_d = 0, max_r = 0;
    
    for (int i = 0; i < 16; i++) {
        scanf("%d", &cube_arr[i]);
    }

    for (int i = 0; i < 16; i++) {
        if (i < 8) {
            max_d = MAX(max_d, cube_arr[i]);
        } else {
            max_r = MAX(max_r, cube_arr[i]);
        }
    }

    if (max_d != max_r) {
        printf("%d \n", -1);
        return 0;
    } else {
        for (int i = 0; i < 8; i++) {
            for (int j = 8; j < 16; j++) {
                max_number += MIN(cube_arr[i], cube_arr[j]);
            }
        }
    }
    
    printf("%d \n", max_number);
    return 0;
}