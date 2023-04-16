#include <bits/stdc++.h>
using namespace std;
const int N = 150;
typedef long long ll;
int mp[N][N], p[N], cnt[10], n, id[N];
ll ans[N];
void dfs(int u, int fa, int val)
{
    p[u] = val;
    ++cnt[val];
    for (int i = 1; i <= n; i++)
    {
        if (i == fa || mp[u][i] == 0) continue;
        dfs(i, u, val^1);
    }
}
int main()
{
    scanf("%d", &n);
    for (int u, v, i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        mp[u][v] = mp[v][u] = 1;
    }
    dfs(1, 0, 0);
    if (cnt[0] > cnt[1])
    {
        swap(cnt[0], cnt[1]);
        for (int i = 1; i <= n; i++)
            p[i] ^= 1;
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 0)
        {
            ans[i] = ((1LL<<60) - 1) ^ (1LL<<num);
            ans[i] ^= (1LL << 59);
            id[i] = num++;
        }
    }
    for (int i = 1; i <= n; i++)
        if (p[i])
        {
            for (int j = 1; j <= n; j++)
                if (mp[i][j])
                    ans[i] ^= (1LL<<id[j]);
            ans[i] ^= (1LL << 59);
        }
    for (int i = 1; i <= n; i++)
        cout<<ans[i]<<" ";
    return 0;
}
/*
1
*/