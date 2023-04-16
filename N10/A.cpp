#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
struct Data
{
    string s;
    int id;
    void input(int _id)
    {
        id = _id;
        cin>>s;
    }
    bool operator <(const Data &t) const {return s < t.s;}
}a[N];

int head[N], etop, tot, pos[N];
struct Edge
{
    int v, nxt;
}e[N<<1];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt = head[u];
    head[u] = etop;
}
void adds(int u, int v)
{
    //cout<<"link:"<<u<<" "<<v<<endl;
    add(u, v); add(v, u);
}

int id(char c)
{
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '.') return 62;
    return 63;
}
const int M = 1e4 + 50;
int h, t, q[M];
void init ()
{
    for (int i = 0; i < 5000; i++)
        q[i] = i + 1;
    h = 0, t = 5000;
}
int ch[M][65], key[M], path[2][M], siz[2];
void recycle(int x)
{
    if (t == 5000) t = 0;
    q[t++] = x;
    key[x] = 0;
    for (int i = 0; i < 65; i++)
        ch[x][i] = 0;
}
int make()
{
    int ret = q[h]; ++h;
    if (h == 5000) h = 0;
    return ret;
}
int add(const char *s, int cur)
{
    int u = 0, len = strlen(s), f = -1;
    siz[cur&1] = 1;
    for (int v, i = 0; i < len; i++)
    {
        v = id(s[i]);
        if (!ch[u][v])
        {
            ch[u][v] = make();
            if (f == -1) f = u;
        }
        u = ch[u][v];
        path[cur&1][++siz[cur&1]] = u;
    }
    if (!key[f]) key[f] = ++tot;
    key[u] = ++tot;
    //cout<<"key:"<<f<<" "<<u<<" "<<key[f]<<" "<<key[u]<<endl;
    if (cur != 1)
    {
        int old = !(cur&1), pre = -1;
        for (int x, i = siz[old]; i; i--)
        {
            x = path[old][i];
            if (key[x])
            {
                if (pre != -1) adds(key[pre], key[x]);
                pre = x;
            }
            if (x == f) break;
        }
        for (int x, i = siz[old]; i; i--)
        {
            x = path[old][i];
            if (x == f) break;
            recycle(x);
        }
    }
    return tot;
}
void finish(int cur)
{
    int old = !(cur&1), pre = -1;
    for (int x, i = siz[old]; i; i--)
    {
        x = path[old][i];
        if (key[x])
        {
            if (~pre) adds(key[pre], key[x]);
            pre = x;
        }
    }
}

int in[N], out[N], tim, fa[N], son[N], cnt[N];
void dfs(int u, int ff)
{
    in[u] = ++tim;
    fa[u] = ff;
    for (int i = head[u]; i; i = e[i].nxt)
        if (e[i].v != ff)
        {
            dfs(e[i].v, u);
            ++son[u];
        }
    out[u] = tim;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++)
        a[i].input(i);
    sort(a + 1, a + n + 1);
    init();
    for (int i = 1; i <= n; i++)
        pos[a[i].id] = add(a[i].s.c_str(), i);
    finish(n + 1);
    dfs(1, 0);
    /*for (int i = 1; i <= n; i++)
        cout<<pos[i]<<" ";
    puts("");*/
    int ans = 0;
    for (int x, i = 1; i <= n ; i++)
    {
        ++ans; x = pos[i]; ++cnt[fa[x]];
        while (cnt[fa[x]] == son[fa[x]] && fa[x] != 1)
        {
            x = fa[x];
            ans -= son[x] - 1;
            ++cnt[fa[x]];
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
6
a.
ac
abd
bc
a/
abc
*/