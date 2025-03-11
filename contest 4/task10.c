#include <stdio.h>
#include <string.h>

int prefix_func(char *line_1, char *line_2) 
{
    int len1 = strlen(line_1);
    int len2 = strlen(line_2);
    
    char new_line_1[len1 + len2 + 2]; 
    char new_line_2[len2 + 1];

    strcpy(new_line_1, line_1);
    strcpy(new_line_2, line_2);

    strcat(new_line_1, " ");
    strcat(new_line_1, new_line_2);

    int res = 0;
    int p[len1 + len2 + 2];
    p[0] = 0;
    
    for (int i = 1; i < strlen(new_line_1); i++) {
        int cur = p[i - 1];

        while (cur > 0 && new_line_1[i] != new_line_1[cur]) {
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
    char line_1[1000002];
    char line_2[1000002];
    
    fgets(line_1, sizeof(line_1), stdin);
    fgets(line_2, sizeof(line_2), stdin);
    
    line_1[strcspn(line_1, "\n")] = 0;
    line_2[strcspn(line_2, "\n")] = 0;
    
    printf("%d %d\n", prefix_func(line_1, line_2), prefix_func(line_2, line_1));
    
    return 0;
}