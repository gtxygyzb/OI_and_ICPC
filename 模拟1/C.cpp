#include <bits/stdc++.h>
using namespace std;
int n, cnt[101], a[101][101];
void output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%d ", a[i][j]);
        puts("");
    }
}
int main()
{
    for (int cs = 1; cs <= 7; cs++)
    {
        memset(a, 0, sizeof(a));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= (1<<cs); i++)
        {
            int x = 0, y = 0;
            while (x < cs)
            {
                a[x][y] ^= 1;
                y = (a[x][y] == 1) ? y : y + 1;
                x = x + 1;
            }
            cout<<y;
            ++cnt[y];

        }
        puts("");
        for (int i = 0; i <= cs; i++)
            cout<<cnt[i]%2;
        puts("");
    }
    return 0;
}