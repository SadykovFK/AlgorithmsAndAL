#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int l;
    scanf("%d", &l);
    getchar();
    char *s = malloc(sizeof(char) * (l + 2));
    fgets(s, l + 2, stdin);
    s[strcspn(s, "\n")] = 0;
    s = realloc(s, sizeof(char) * (l + 1));
    int flag = 1;
    for (int i = 0; i < l / 2; i++) {
        if (s[i] != s[l - 1 - i]) {
            flag = 0;
            printf("%s", "NO\n");
            free(s);
            return 0;
        }
    }
    if (flag) printf("%s", "YES\n");
    free(s);
    return 0;
}