#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x_move[] = {2, -2, -1, -1, 1, 1, 2, -2};
int y_move[] = {1, 1, -2, 2, -2, 2, -1, -1};

int not_out(int n, int x, int y)
{
   return (x >= 1) && (x <= n) && (y >= 1) && (y <= n);
}

int bfs(int n, int xn, int yn, int xk, int yk)
{
    int done[n + 1][n + 1];
    memset(done, 0, sizeof(done));

    int line_x[n * n];
    int line_y[n * n];
    int fr = 0, re = 0;

    line_x[re] = xn;
    line_y[re++] = yn;
    done[xn][yn] = 1;

    while (fr < re) {
        int cur_x = line_x[fr];
        int cur_y = line_y[fr++];

        if ((cur_x == xk) && (cur_y == yk)) {
            return done[cur_x][cur_y] - 1;
        }

        for (int i = 0; i < 8; i++) {
            int new_x = cur_x + x_move[i];
            int new_y = cur_y + y_move[i];

            if (not_out(n, new_x, new_y) && !done[new_x][new_y]) {
                done[new_x][new_y] = done[cur_x][cur_y] + 1;
                line_x[re] = new_x;
                line_y[re++] = new_y;
            }
        }
    }

    return -1;
}

int main(void)
{
    int n;
    int xn, yn, xk, yk;
    scanf("%d %d %d %d %d", &n, &xn, &yn, &xk, &yk);

    int ans = bfs(n, xn, yn, xk, yk);
    printf("%d\n", ans);
    
    return 0;
}