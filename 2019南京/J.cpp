#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 450, inf = 0x3f3f3f3f;

int n, delta, pre[N], slack[N];
int w[N][N], la[N], lb[N], match[N];
bool vb[N];

void bfs(int x)
{
    int a, y = 0, y1 = 0;
    for (int i = 1; i <= n; i++)
        pre[i] = 0, slack[i] = inf;
    match[y] = x;
    do
    {
        a = match[y], delta = inf, vb[y] = 1;
        for (int b = 1; b <= n; b++)
            if (!vb[b])
            {
                if (slack[b] > la[a] + lb[b] - w[a][b])
                    slack[b] = la[a] + lb[b] - w[a][b], pre[b] = y;
                if (slack[b] < delta)
                    delta = slack[b], y1 = b;
            }
        for (int b = 0; b <= n; b++)
            if (vb[b])
                la[match[b]] -= delta, lb[b] += delta;
            else slack[b] -= delta;
        y = y1;
    }while (match[y]);
    for (; y; y = pre[y]) match[y] = match[pre[y]];
}
ll KM()
{
    for (int i = 1; i <= n; i++)
        match[i] = la[i] = lb[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vb, 0, sizeof(vb));
        bfs(i);
    }
    ll res = 0;
    for(int y = 1; y <= n; ++ y)
        res += w[match[y]][y];
    return res;
}

int p[N];
ll a[N], b[N], c[N];
int main()
{
	scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &b[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &c[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ll pp = b[i] + c[j];
            int cc = 0;
            for (int k = 1; k <= n; k++)
                if (pp > a[k]) cc += p[k];
            w[i][j] = cc;
        }
    }
	printf("%lld\n", KM());
    return 0;
}