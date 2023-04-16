#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50, dx[] = {0, 0, 0, -1, 1}, dy[] = {0, 1, -1, 0, 0};
char s[N];
int n, a[10], mx, my, b[N];
int id(char c)
{
    if (c == 'U') return 1;
    if (c == 'D') return 2;
    if (c == 'L') return 3;
    return 4;
}

int ans[N], cnt[10];
bool check()
{
    int p[] = {1, 2, 3, 4};
    do
    {
        memcpy(cnt, a, sizeof(cnt));
        int x = 0, y = 0, flag = 1, top = 0;
        for (int i = 0; i < 4 && flag; i++)
        {
            int u = p[i];
            while (cnt[u])
            {
                x += dx[u]; y += dy[u];
                if (mx == x && my == y) flag = 0;
                --cnt[u];
                ans[++top] = u;
            }
        }
        if (flag)
        {
            for (int i = 1; i <= n; i++)
            {
                char c;
                if (ans[i] == 1) c = 'U';
                else if (ans[i] == 2) c = 'D';
                else if (ans[i] == 3) c = 'L';
                else c = 'R';
                printf("%c", c);
            }
            puts("");
            return 1;
        }
    } while (next_permutation(p, p + 4));
    
    return 0;
}
int main()
{
    srand(time(0));
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(a, 0, sizeof(a));
        scanf("%d%d", &mx, &my);
        scanf("%s", s + 1);
        n = strlen(s + 1);

        for (int i = 1; i <= n; i++)
            ++a[id(s[i])];

        int fy = a[1] - a[2], fx = a[4] - a[3];
        if (fx == mx && fy == my || (mx == 0 && my == 0))
        {
            puts("Impossible");
            continue;
        }
        if (!check()) puts("Impossible");
    }
    return 0;
}