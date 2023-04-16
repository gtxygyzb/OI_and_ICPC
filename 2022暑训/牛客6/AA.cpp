#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 50, M = 1<<19;
int n, a[N], c[N], bin[25];
queue <int> q[25];

void dfs(int u, int d)
{
    if (d > 19) return ;
    if (!q[d].empty())
    {
        int cur = q[d].front();
            q[d].pop();
        for (int i = u; i <= M; i += bin[d])
            c[i] = cur;
    }
    else
    {
        dfs(u, d + 1);
        dfs(u + bin[d], d + 1);
    }
}
int main()
{
    scanf("%d", &n);
    bin[0] = 1;
    for (int i = 1; i <= 20; i++)
        bin[i] = bin[i - 1] << 1;
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for (int i = 1; i <= n; i++)
    {
        int cur = 2, lg = 1;
        while (cur * 2 <= a[i]) cur *= 2, ++lg;
        q[lg].push(i);
    }
    dfs(0, 1); dfs(1, 1);
    printf("%d\n", M);
    for (int i = 0; i < M; i++)
    {
        if (c[i] == 0) printf("1 ");
        else printf("%d ", c[i]);
    }
    return 0;
}