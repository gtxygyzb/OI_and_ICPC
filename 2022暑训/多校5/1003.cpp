#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;

int head[N], etop;
struct Edge
{
    int v, w, nxt;
}e[N << 1];
void add(int u, int v, int w)
{
    e[++etop] = Edge{v, w, head[u]};
    head[u] = etop;
}

int n;
vector <int> vec[N];
void init()
{
    for (int i = 0; i <= n; i++)
    {
        head[i] = 0;
        vec[i].clear();
    }
    etop = 0;
}

void dfs(int u, int fa, int dep)
{
    vec[dep].push_back(u);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        init();
        for (int u, v, w, i = 1; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        dfs(1, 0, 0);
    }
    return 0;
}
/*
1
6
6 1 2
3 5 2
2 4 6
5 2 2
5 6 20
3 8
6 5
*/