#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 50;
typedef long long ll;
ll P, Q, x, y;

int vis[N], tot, pri[N];
void init()
{
    for (int i = 2; i <= N - 50; i++)
    {
        if (vis[i] == 0) pri[++tot] = i;
        for (int j = 1; j <= tot && i * pri[j] <= N - 50; j++)
        {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}

ll a[N], top;
int main()
{
    int T;
    scanf("%d", &T);
    init();
    while (T--)
    {
        scanf("%lld%lld%lld", &P, &Q, &y);
        ll t = P * Q - 1; top = 0;
        for (int j = 1; j <= tot && t > 1; j++)
            if (t % pri[j] == 0)
            {
                a[++top] = pri[j];
                while (t % pri[j] == 0) t /= pri[j];
            }
        if (t > 1) a[++top] = t;

        int ans = 0;
        for (int i = 1; i <= top; i++)
        {
            if (a[i] <= P || a[i] <= Q || a[i] <= y) continue;
            x = Q * y % a[i];
            ++ans;
        }
        if (ans > 1 || ans == 0) puts("shuanQ");
        else printf("%lld\n", x);
    }
    return 0;
}
/*
2
5 5 5
6 6 6
*/