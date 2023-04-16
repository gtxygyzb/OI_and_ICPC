#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 50;
int a[N], top, vis[N], pri[N];
void init()
{
    for (int i = 2; i <= N - 50; i++)
    {
        if (vis[i] == 0)
        {
            pri[++top] = i;
            a[i] = 1;
        }
        for (int j = 1; j <= top; j++)
        {
            int u = i * pri[j];
            if (u > N - 50) break;
            vis[u] = 1;
            a[u] = a[i] + 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}
int main()
{
    init();
    /*for (int i = 1; i <= 30; i++)
        cout<<a[i]<<" ";*/
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        int ans = 0;
        for (int x, i = 1; i <= n ; i++)
        {
            scanf("%d", &x);
            ans ^= a[x];
        }
        puts(!ans ? "Bob" : "Alice");
    }
    return 0;
}