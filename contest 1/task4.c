#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n;
    int num = 0;
    int prev = INT_MIN;
    int cnt = 0, max_cnt = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (prev < num) {
            cnt += 1;
        } else {
            if (max_cnt < cnt) {
                max_cnt = cnt;
            }
            cnt = 1;
        }
        prev = num;
    }
    
    if (max_cnt < cnt) {
        max_cnt = cnt;
    }

    printf("%d\n", max_cnt);
    return 0;
}
