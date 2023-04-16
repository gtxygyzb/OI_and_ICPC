#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;

multiset <int> se[N];
int ch[N][26], top, val[N], pos[N];
int fail[N], last[N];
void add(char *s, int id)
{
    int u = 0, len = strlen(s);
    for (int v, i = 0; i < len; i++)
    {
        v = s[i] - 'a';
        if (!ch[u][v]) ch[u][v] = ++top;
        u = ch[u][v];
    }
    se[u].insert(0);
    ++val[u];
    pos[id] = u;
}
void getfail()
{
    queue <int> q;
    for (int u, i = 0; i < 26; i++)
    {
        u = ch[0][i];
        if (u)
        {
            q.push(u);
            fail[u] = last[u] = 0;
        }
    }
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (int u, v, i = 0; i < 26; i++)
            if (ch[cur][i])
            {
                u = ch[cur][i];
                q.push(u);
                v = fail[cur];
                while (v && !ch[v][i]) v = fail[v];
                fail[u] = ch[v][i];
                last[u] = val[fail[u]] ? fail[u] : last[fail[u]];
            }
    }
}

int tim, vis[N];
int work(char *s)
{
    int ret = -1, len = strlen(s), u = 0;
    ++tim;
    for (int c, i = 0; i < len; i++)
    {
        c = s[i] - 'a';
        while (u && !ch[u][c]) u = fail[u];
        u = ch[u][c];
        //cout<<u<<": "<<last[u]<<" "<<val[u]<<endl;
        int uu = u;
        while (uu && vis[uu] != tim)
        {
            if (val[uu])
            {
                ret = max(ret, *se[uu].rbegin());
                //cout<<"uu: "<<*se[uu].rbegin()<<endl;
            }
            vis[uu] = tim;
            uu = last[uu];
        }
    }
    return ret;
}
char s[N];
int n, q, a[N];
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        add(s, i);
    }
    getfail();
    for (int op, i, x; q--;)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d", &i, &x);
            se[pos[i]].erase(se[pos[i]].lower_bound(a[i]));
            a[i] = x;
            se[pos[i]].insert(a[i]);
        }
        else
        {
            scanf("%s", s);
            printf("%d\n", work(s));
        }
    }
    return 0;
}
/*
2 3
a
ba
1 2 10
1 1 11
2 baa
*/