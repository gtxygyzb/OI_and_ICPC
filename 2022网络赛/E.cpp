#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 50;
typedef long long ll;
int n, a[N];

int head[N], etop;
ll f[N][2]; //0 选根，第一类路径,1 不选根第二类路径
struct Edge
{
    int v, nxt;
}e[N << 1];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt = head[u];
    head[u] = etop;
}

int dep[N], anc[N][21];
void work(int u, int fa)
{
    anc[u][0] = fa;
    for (int i = 1; i <= 20; i++)
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    dep[u] = dep[fa] + 1;
    if (dep[u] == 1) {f[u][0] = f[u][1] = 0;}
    else if (dep[u] == 2) {f[u][0] = a[u] ^ a[fa]; f[u][1] = 0;}
    else if (dep[u] & 1) //奇数
    {
        f[u][0] = f[fa][0]; //当前点多出来
        /*if (u == 14)
        {
            puts("fdsafdsafdsaf");
            cout<<anc[u][1]<<": "<<f[anc[u][1]][1] <<endl;
            cout<<a[u]<<" "<<a[fa]<<endl;
        }*/
        f[u][1] = f[anc[u][1]][1] + (a[u] ^ a[fa]); //根多出来
    }
    else //偶数
    {
        f[u][0] = f[anc[u][1]][0] + (a[u] ^ a[fa]);
        f[u][1] = f[fa][1];
    }
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa) continue;
        work(v, u);
    }
}
int getlca(int x,int y)
{
    if (dep[x]>dep[y]) swap(x,y);
	int d=dep[y]-dep[x];
	for (int i=0;i<=20;i++)
		if ((1<<i)&d) y=anc[y][i];
	
	for (int i=20;i>=0;i--)
		if (anc[x][i]!=anc[y][i])
		{
			x=anc[x][i];
			y=anc[y][i];
		}
	return x==y ? x : anc[x][0];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for (int u, v, i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }

    work(1, 0);
    /*for (int i = 1; i <= n; i++)
        cout<<i<<" "<<f[i][0]<<" "<<f[i][1]<<endl;*/
    int m;
    scanf("%d", &m);
    for (int x, y; m--;)
    {
        scanf("%d%d", &x, &y);
        int lca = getlca(x, y); 
        //cout<<"lca: "<<lca<<endl;
        ll ans = 0;
        int len = dep[x] - dep[lca] + 1;
        if ((len & 1) == 0) //lca跟x算
        {
            ans += f[x][dep[x]&1] - f[lca][dep[x]&1];
            if (((dep[y] - dep[lca]) & 1) != 0)
                y = anc[y][0];

            ans += f[y][dep[y]&1] - f[lca][dep[y]&1];
        }

        else // lca和y算
        {
            ans += f[x][dep[x]&1] - f[lca][dep[x]&1];
            if (((dep[y] - dep[lca] + 1) & 1) != 0)
                y = anc[y][0];
            ans += f[y][dep[y]&1] - f[lca][dep[y]&1];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
16
1 1 4 5 1 4 2 3 5 7 7 6 5 4 3 2
1 2
1 3
2 5
4 2
6 3
8 4
4 9
7 5
10 6
11 7
7 12
13 8
10 15
9 14
16 10

*/