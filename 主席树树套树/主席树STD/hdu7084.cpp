#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+50;
int n, q, rt[N];
char s[N];

struct Seg
{
    int top;
    struct node{
        int l,r;
        int sum;
        void init() {l = r = sum = 0;}
    }t[N*20];
    void init()
    {
        for (int i = 1; i <= top; i++)
            t[i].init();
        top = 0;
    }
    void add(int &u,int pre,int l,int r,int pos)
    {
        t[u=++top]=t[pre]; ++t[u].sum;
        if (l==r) return ;
        int mid=l+r>>1;
        if (pos<=mid) add(t[u].l,t[pre].l,l,mid,pos);
        else add(t[u].r,t[pre].r,mid+1,r,pos);
    }
    int query(int l,int r,int old,int now,int nl,int nr)
    {
        if(nl==l&&nr==r){
            return t[now].sum-t[old].sum;
        }
        int mid=(l+r)>>1;
        if(nr<=mid) return query(l,mid,t[old].l,t[now].l,nl,nr);
        if (nl>mid) return query(mid+1,r,t[old].r,t[now].r,nl,nr);
        return query(l,mid,t[old].l,t[now].l,nl,mid)+query(mid+1,r,t[old].r,t[now].r,mid+1,nr);
    }
}seg;

struct Tree
{
    int etop, head[N];
    int in[N], out[N], tim, dfm[N];
    void init() {etop = tim = 0; memset(head, 0, sizeof(head));}
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
    void adds(int u, int v) {add(u, v); add(v, u);}
    void dfs(int u, int fa)
    {
        in[u] = ++tim;
        dfm[tim] = u;
        for (int i = head[u]; i; i = e[i].nxt)
            if (e[i].v != fa) dfs(e[i].v, u);
        out[u] = tim;
    }
}t1, t2;

int nxt1[N], nxt2[N];
void work()
{
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int j = 0, i = 2; i <= n; i++)
    {
        while (j && s[i] != s[j+1]) j = nxt1[j];
        if (s[i] == s[j+1]) ++j;
        nxt1[i] = j;
    }
    nxt2[n] = n + 1;
    for (int j = n + 1, i = n - 1; i >= 1; i--)
    {
        while (j <= n && s[i] != s[j-1]) j = nxt2[j];
        if (s[i] == s[j-1]) --j;
        nxt2[i] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        t1.add(nxt1[i], i);
        t2.add(nxt2[i] - 1, i - 1);
    }
    t1.dfs(0, 0);
    t2.dfs(n, 0);
    for (int i = 1; i <= n + 1; i++)
        seg.add(rt[i], rt[i-1], 1, n + 1, t1.in[t2.dfm[i]]);

    for (int x, y; q--;)
    {
        scanf("%d%d", &x, &y);
        y = n - y;
        printf("%d\n", seg.query(1, n + 1, rt[t2.in[y] - 1], rt[t2.out[y]], t1.in[x], t1.out[x]));
    }
}
void init()
{
    t1.init();
    t2.init();
    seg.init();
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        work();
    }
    return 0;
}
/*
2
6 3
ababaa
1 1
2 1
3 1

6 3
aaaaaa
5 5
1 1
2 3
*/