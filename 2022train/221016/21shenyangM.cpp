#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 50;
int n, ans[N];
struct SAM
{
    int fa[N], ch[N][26], mx[N], pos[N], last, top, vis[N];
    int t[N], rk[N];
    SAM () {last = top = 1;}
    void add(int c, int id)
    {
        int p = last, np = last = ++top;
        mx[np] = mx[p] + 1;
        pos[last] = id;
        for (; !ch[p][c] && p; p = fa[p]) ch[p][c] = np;
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

    void work()
    {
        for (int i = 1; i <= top; i++) ++t[mx[i]];
        for (int i = 1; i <= top; i++) t[i] += t[i - 1];
        for (int i = top; i >= 1; i--) rk[t[mx[i]]--] = i;
        for (int u, i = top; i >= 2; i--)
        {
            u = rk[i];
            pos[fa[u]] = min(pos[fa[u]], pos[u]);
        }
    }

    void query(int u, int len)
    {
        vis[u] = 1;
        for (int i = 25; ~i; i--)
            if (ch[u][i] && vis[ch[u][i]] == 0)
                query(ch[u][i], len + 1);
        for (int cur = pos[u]; cur <= n && !ans[cur]; ++cur)
            ans[cur] = len;
    }

}sam;
char s[N];
int main()
{
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++)
        sam.add(s[i] - 'a', i + 1);
    sam.work();
    sam.query(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", i - ans[i] + 1, i);
    return 0;
}