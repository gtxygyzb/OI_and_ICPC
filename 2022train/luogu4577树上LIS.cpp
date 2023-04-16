#include <bits/stdc++.h>
using namespace std;
typedef multiset <int>::iterator IT;
const int N = 4e5 + 50;

int head[N], etop;
struct Edge
{
    int v, nxt;
}e[N];
void add(int u, int v)
{
    e[++etop] = {v, head[u]};
    head[u] = etop;
}
int n, w[N];
multiset <int> s[N];

void merge(int u, int v)
{
    if (s[u].size() < s[v].size()) swap(s[u], s[v]);
    for (IT it = s[v].begin(); it != s[v].end(); ++it)
        s[u].insert(*it);
}
void output(int u)
{
    printf("%d: ", u);
    for (IT it = s[u].begin(); it != s[u].end(); ++it)
        printf(" %d ", *it);
    puts("");
}
void dfs(int u)
{
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        dfs(v = e[i].v);
        merge(u, v);
    }
    s[u].insert(w[u]);
    IT it = s[u].lower_bound(w[u]);
    if (it != s[u].begin()) s[u].erase(--it);
    //output(u);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", w+i);
    for (int fa, i = 2; i <= n; i++)
    {
        scanf("%d", &fa);
        add(fa, i);
    }
    dfs(1);
    printf("%d\n", s[1].size());
    return 0;
}