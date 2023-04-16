#include <bits/stdc++.h>
using namespace std;
typedef set<int>::iterator IT;
const int N = 5e5 + 50;

int head[N], etop;
struct Edge
{
    int v, nxt;
}e[N];
void add(int u, int v)
{
    e[++etop] = Edge{v, head[u]};
    head[u] = etop;
}
int n, a[N], ans;
set <int> s[N];
void output(int id, set <int> se)
{
    cout<<id<<": ";
    for (IT it = se.begin(); it != se.end(); ++it)
        cout<< *it <<" ";
    puts("");
}
void dfs(int u, int fa, int w)
{
    int flag = 1;
    s[u].insert(w);
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == fa) continue;
        dfs(v, u, w ^ a[v]);
        if (flag)
        {
            if (s[u].size() < s[v].size()) swap(s[u], s[v]);
            for (IT it = s[v].begin(); it != s[v].end(); ++it)
            {
                int val = *it;
                //cout<<"v: "<<v<<" "<<val<<endl;
                if (s[u].find(val ^ a[u]) != s[u].end())
                {
                    ++ans;
                    flag = 0;
                    break;
                }
            }
            if (flag)
                for (IT it = s[v].begin(); it != s[v].end(); ++it)
                    s[u].insert(*it);
        }
    }
    if (!flag) s[u].clear();
    //output(u, s[u]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for (int u, v, i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs(1, 0, a[1]);
    printf("%d\n", ans);
    return 0;
}