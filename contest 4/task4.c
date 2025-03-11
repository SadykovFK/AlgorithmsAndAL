#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[256];
    fgets(line, 256, stdin);
    line[strcspn(line, "\n")] = 0;

    int j = 0;
    while (j != strlen(line)) {
        int pos = 0;
        int even = 0, odd = 0;
        for (int i = 0; i < strlen(line); i++) {
            if (i != j) {
                if (line[i] == 'A') {
                    if ((pos + 1) % 2 == 0) even++;
                    else odd++;
                }
                pos++;    
            }   
        }

        if (odd == even) {
            printf("%d ", j + 1);
        }

        j++;
    }
    return 0;
}