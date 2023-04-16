#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n, m, fa[N], pre[N];
int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int head[N], etop;
int ans[N], top, id[N];
struct Edge
{
    int v, w, nxt;
}e[N << 1];
void add(int u, int v, int w)
{
    e[++etop] = Edge{v, w, head[u]};
    head[u] = etop;
}

int flag;
void dfs(int u, int f, int ed, int num)
{
    if (flag) return ;
    pre[u] = f;
    id[u] = num;
    if (u == ed)
    {
        for (int k = u; k; k = pre[k])
            ans[++top] = id[k];
        sort(ans + 1, ans + top + 1);
        flag = 1;
        return ;
    }
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == f) continue;
        dfs(v, u, ed, e[i].w);
    }
}
int main()
{
    //puts("dsdasfsadf");
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
            head[i] = 0;
            pre[i] = 0;
        }
        etop = flag = 0;
        for (int u, v, i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            if (flag) continue;
            int fu = find(u), fv = find(v);
            if (fu == fv)
            {
                top = 1;
                ans[top] = i;
                dfs(u, 0, v, -1);
            }
            else
            {
                fa[fv] = fu;
                add(u, v, i);
                add(v, u, i);
            }
        }
        if (flag == 0) puts("-1");
        else
        {
            for (int k = 2; k <= top; k++)
            printf("%d%c", ans[k], k == top ? '\n' : ' ');
        }
    }
    return 0;
}
/*
4
6 8
1 2
2 3
5 6
3 4
2 5
5 4
5 1
4 2

4 2
1 2
4 3

6 8
1 2
2 3
5 6
3 4
2 5
5 4
5 1
4 2

4 4
1 2
4 3
2 4
1 3
*/