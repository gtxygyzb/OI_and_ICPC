#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 50, inf = 0x3f3f3f3f;
char s[N];
int ans[N], n;
vector <int> e[N];
struct SAM
{
    int fa[N], ch[N][26], mx[N], last, top, pos[N], vis[N];

    SAM () {last = top = 1;}
    void add(int c, int id)
    {
        int p = last, np = last = ++top;
        mx[np] = mx[p] + 1; pos[np] = id;
        for (; !ch[p][c] && p; p = fa[p])
            ch[p][c] = np;
        if (!p) fa[np] = 1;
        else
        {
            int q = ch[p][c];
            if (mx[q] == mx[p] + 1) fa[np] = q;
            else
            {
                int nq = ++top;
                fa[nq] = fa[q];
                mx[nq] = mx[p] + 1;
                fa[q] = fa[np] = nq;
                pos[nq] = id;
                memcpy(ch[nq], ch[q], sizeof(ch[nq]));
                for (; ch[p][c] == q; p = fa[p])
                    ch[p][c] = nq;
            }
        }
    }
    void dfs(int u)
    {
        for (int i = 0; i < e[u].size(); i++)
        {
            dfs(e[u][i]);
            pos[u] = min(pos[u], pos[e[u][i]]);
        }
    }
    void solve(int u, int len)
    {
        //cout<<"u: "<<u<<" "<<pos[u]<<endl;
        vis[u] = 1;
        for (int i = 25; ~i; i--)
        {
            if (!ch[u][i] || vis[ch[u][i]]) continue;
            solve(ch[u][i], len + 1);
        }
        int p = pos[u];
        for (int p = pos[u]; p <= n && !ans[p]; p++)
            ans[p] = len;
    }
    void work()
    {
        for (int i = 2; i <= top; i++)
            e[fa[i]].push_back(i);
        dfs(1);
        pos[1] = inf;
        solve(1, 0);
        for (int i = 1; i <= n; i++)
            printf("%d %d\n", i - ans[i] + 1, i);
    }
}sam;

int main()
{
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++)
        sam.add(s[i] - 'a', i + 1);
    sam.work();
    return 0;
}
/*
tat
*/