#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3 + 50;
const ll inf = 1e18;
int n, hp[N], siz[N];
ll f[N][N][2];
int head[N], etop;
struct Edge
{
    int v, nxt;
}e[N];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt = head[u];
    head[u] = etop;
}

void dp(int u)
{
    siz[u] = 1;
	f[u][0][0] = hp[u], f[u][1][1] = 0;

    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        dp(v = e[i].v);
        for (int j = siz[u] - 1; ~j; j--) //已经用了j张魔法卡，自己不用
            for (int k = siz[v]; ~k; k--) //新子树用了k张魔法卡
                if (k == 0)
                    f[u][j][0] += f[v][0][0] + hp[v];
                else
                    f[u][j + k][0] = min(f[u][j + k][0], f[u][j][0] + min(f[v][k][0] + hp[v], f[v][k][1]));

        for (int j = siz[u]; ~j; j--) //已经用了j张魔法卡，自己用
            for (int k = siz[v]; ~k; k--) //新子树用了k张魔法卡
                if (k == 0)
                    f[u][j][1] += f[v][0][0];
                else
                    f[u][j + k][1] = min(f[u][j + k][1], f[u][j][1] + min(f[v][k][0], f[v][k][1]));
        siz[u] += siz[v];
    }
}
void work()
{
    for (int fa, i = 2; i <= n; i++)
    {
        scanf("%d", &fa);
        add(fa, i);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", hp+i);
    dp(1);
    for (int i = 0; i <= n; i++)
        printf("%lld ", min(f[1][i][0], f[1][i][1]));
    puts("");
}
void init()
{
	etop = 0;
	memset(head, 0, sizeof(int) * (n + 5));
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			f[i][j][0] = f[i][j][1] = inf;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        init();
        work();
    }
    return 0;
}