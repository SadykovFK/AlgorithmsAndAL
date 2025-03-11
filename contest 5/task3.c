#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    int capacity = 3;
    int *numbers = malloc(sizeof(int) * 3);

    scanf("%d", &num);
    int i = 0;
    while (num != 0) {
        if (capacity == (i + 1)) {
            capacity *= 3;
            int *temp_numbers = numbers;
            temp_numbers = realloc(numbers, sizeof(int) * capacity);
            if (temp_numbers == NULL) {
                free(numbers);
                return 1;
            }
            numbers = temp_numbers;
        }
        numbers[i] = num;    
        i++;
        scanf("%d", &num);
    }

    for (int j = 0; j < i; j += 2) {
        printf("%d ", numbers[j]);
    }

    for (int j = 1; j < i; j += 2) {
        printf("%d ", numbers[j]);
    }
    printf("\n");

    free(numbers);
    return 0;
}