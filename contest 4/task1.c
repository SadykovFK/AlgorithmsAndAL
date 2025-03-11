#include <stdio.h>
#include <string.h>

int prefix_func(char *line_1, char *line_2)
{
    char new_line_1[30003];
    char new_line_2[30003];

    for (int i = 0; i < 30003; i++) {
        new_line_1[i] = '\0';
        new_line_2[i] = '\0'; 
    }


    for (int i = 0; i < strlen(line_1); i++) {
        new_line_1[i] = line_1[i];
    }

    for (int i = 0; i < strlen(line_2); i++) {
        new_line_2[i] = line_2[i];
    }

    strcat(new_line_1, " ");
    strcat(new_line_1, new_line_2);

    int res = 0;
    int p[30003] = {0};
    
    for (int i = 1; i < strlen(new_line_1); i++) {
        int cur = p[i - 1];

        while ((new_line_1[i] != new_line_1[cur]) && (cur > 0)) {
            cur = p[cur - 1];
        } 

        if (new_line_1[i] == new_line_1[cur]) {
            cur++;
        }

        p[i] = cur;
        res = cur;
    }
    return res;
}

int main(void)
{
    char line_1[30003];
    char line_2[30003];
    fgets(line_1, 30003, stdin);
    fgets(line_2, 30003, stdin);
    line_1[strcspn(line_1, "\n")] = 0;
    line_2[strcspn(line_2, "\n")] = 0;
    printf("%d %d\n", prefix_func(line_1, line_2), prefix_func(line_2, line_1));
    return 0;
}