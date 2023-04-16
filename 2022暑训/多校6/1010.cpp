#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 50;
int fa[N], etop;
int find(int x)
{
	if (fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
struct Edge
{
	int u, v, w;
}e[N];
int cmp(Edge e1, Edge e2)
{
	return e1.w > e2.w;
}
int n, m, ans[N], top, u[N], v[N];
map <int, int> mp[N];

void init()
{
    for (int i = 1; i <= n; i++)
        {fa[i] = i; mp[i].clear();}
    etop = top = 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", u + i, v + i);
            if (u[i] > v[i]) swap(u[i], v[i]);
            if (u[i] == v[i]) ans[++top] = i;
            else if (mp[u[i]][v[i]]) ans[++top] = mp[u[i]][v[i]];
            mp[u[i]][v[i]] = i;
        }
        for (int i = 1; i <= m; i++)
            if (u[i] != v[i] && mp[u[i]][v[i]] == i)
            {
                //cout<<"edge: "<<u[i]<<" "<<v[i]<<" "<<i<<endl;
                e[++etop] = Edge{u[i], v[i], i};
            }
        /*for (int i = 1; i <= top; i++)
            cout<<ans[i]<<" ";
        puts("");*/
        sort(e+1, e+etop+1, cmp);
        for (int i = 1; i<=etop; i++)
        {
            int fu=find(e[i].u), fv=find(e[i].v);
            if (fu!=fv)
                fa[fu]=fv;
            else ans[++top] = e[i].w;
        }
        if (top == 0) puts("0\n");
        else
        {
            printf("%d\n", top);
            sort(ans + 1, ans + top + 1);
            for (int i = 1; i <= top; i++)
                printf("%d ", ans[i]);
            puts("");
        }
    }
    return 0;
}
/*
3
5 7
1 1
1 2
1 3
3 4
3 4
2 4
2 5
5 4
1 2
2 3
3 4
4 5
5 7
1 1
1 2
1 3
3 4
3 4
2 4
2 5
*/