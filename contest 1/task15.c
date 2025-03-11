#include <stdio.h>

int main(void)
{
    int n;
    int pp_x, pp_y, p_x, p_y, x, y;
    int cur_vecx, cur_vecy, prev_vecx, prev_vecy;
    int prev_res;
    scanf("%d", &n);
    scanf("%d %d %d %d %d %d", &pp_x, &pp_y, &p_x, &p_y, &x, &y);
    int fst_x = pp_x;
    int fst_y = pp_y;
    prev_vecx = p_x - pp_x;
    prev_vecy = p_y - pp_y;
    int fst_vecx = prev_vecx;
    int fst_vecy = prev_vecy;
    cur_vecx = x - p_x;
    cur_vecy = y - p_y;
    prev_res = prev_vecx * cur_vecy - cur_vecx * prev_vecy;
    p_x = x;
    p_y = y;
    prev_vecx = cur_vecx;
    prev_vecy = cur_vecy;
    for (int i = 0; i < (n - 1); i++) 
    {
        int res;
        if (i == (n - 3))
        {
            cur_vecx = fst_x - p_x;
            cur_vecy = fst_y - p_y;
        }
        else if (i == (n - 2))
        {
            cur_vecx = fst_vecx;
            cur_vecy = fst_vecy;
        }
        else
        {
            scanf("%d %d", &x, &y);
            cur_vecx = x - p_x;
            cur_vecy = y - p_y;
        }
        res = prev_vecx * cur_vecy - cur_vecx * prev_vecy;
        if (((res < 0) && (prev_res < 0)) || ((res > 0) && (prev_res > 0)))
        {
            prev_vecx = cur_vecx;
            prev_vecy = cur_vecy;
            p_x = x;
            p_y = y;
            prev_res = res;
        }
        else
        {
            printf("%s", "No\n");
            return 0;
        }
    }
    printf("%s", "Yes\n");
    
    return 0;
}