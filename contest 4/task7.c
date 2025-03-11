#include <stdio.h>
#include <string.h>

char cities[11][22] = {0};
int n;
int maxLength;
char keyCities[11][22] = {0};
int cnt;

void citiesGame(int length, int index, int *used, char last)
{
    int flag = 0;

    for (int i = 0; i < n; i++) {
        if ((!used[i]) && (cities[i][0] == last)) {
            used[i] = 1;
            citiesGame(length + 1, index, used, cities[i][strlen(cities[i]) - 1]);
            used[i] = 0;
            flag = 1;
        }
    }

    if (!flag) {
        if (length > maxLength) {
            maxLength = length;
            cnt = 1;
            strcpy(keyCities[0], cities[index]);
        } else if (length == maxLength) {
            int inFlag = 1;
            for (int i = 0; i < cnt; i++) {
                if (strcmp(keyCities[i], cities[index]) == 0) {
                    inFlag = 0;
                    break;
                }
            }
            if (inFlag) {
                strcpy(keyCities[cnt++], cities[index]);
            }
        }
    }
}

int main(void)
{
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(cities[i], 22, stdin);
        cities[i][strcspn(cities[i], "\n")] = 0;
    }

    int used[11] = {0};
    maxLength = 0;
    cnt = 0;

    for (int i = 0; i < n; i++) {
        used[i] = 1;
        citiesGame(1, i, used, cities[i][strlen(cities[i]) - 1]);
        used[i] = 0;
    }

    printf("%d\n", maxLength);
    
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", keyCities[i]);
    }

    return 0;
}