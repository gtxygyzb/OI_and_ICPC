#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;

int n, m, top = 1;
char s[N];
struct Node
{
    Node *lc, *rc;
    int val;
    Node () : val(0) {lc = rc = NULL;}
};
struct Tree
{
    Node *rt;
    Tree() {rt = NULL;}
    void add(Node *&u, int l, int r, int pos, int val)
    {
        if (!u) u = new Node();
        u->val += val;
        if (l == r) return ;
        int mid = l + r >> 1;
        if (pos <= mid) add(u->lc, l, mid, pos, val);
        else add(u->rc, mid + 1, r, pos, val);
    }
    int query(Node *&u, int st, int ed, int l, int r)
    {
        if (!u) return 0;
        if (st == l && ed == r) return u->val;
        int mid = l + r >> 1, ret = 0;
        if (st <= mid) ret += query(u->lc, st, min(mid, ed), l, mid);
        if (ed > mid) ret += query(u->rc, max(st, mid + 1), ed, mid + 1, r);
        return ret;
    }
}t[N];

int cnt[2];
void add(int x, int pos, int val)
{
    for (; x <= top; x += x & -x)
    {
        //cout<<"ad: "<<x<<" "<<pos<<" "<<val<<endl;
        t[x].add(t[x].rt, 1, n, pos, val);
    }
}

int ask(int pre, int cur, int l, int r)
{
    int ret = 0;
    for (int i = pre; i; i -= i & -i)
        ret -= t[i].query(t[i].rt, l, r, 1, n);
    for (int i = cur; i; i -= i & -i)
        ret += t[i].query(t[i].rt, l, r, 1, n);
    return ret;
}

struct Trie
{
    int ch[N][26], pos[N];
    int in[N], out[N], dfn;
    void insert(char *s, int id)
    {
        int u = 1, len = strlen(s);
        for (int v, i = 0; i < len; i++)
        {
            v = s[i] - 'a';
            if (!ch[u][v]) ch[u][v] = ++top;
            u = ch[u][v];
        }
        pos[id] = u;
    }
    void dfs(int u)
    {
        in[u] = ++dfn;
        for (int i = 0; i < 26; i++)
            if (ch[u][i]) dfs(ch[u][i]);
        out[u] = dfn;
    }
    int qpos(char *s, int k)
    {
        int u = 1;
        for (int v, i = 0; i < k; i++)
        {
            v = s[i] - 'a';
            if (!ch[u][v]) return -1;
            u = ch[u][v];
        }
        return u;
    }
    void work()
    {
        for (int i = 1; i <= n; i++)
            add(in[pos[i]], i, 1);
        for (int opt, k, l, r, i = 1; i <= m; i++)
        {
            scanf("%d", &opt);
            if (opt == 1)
            {
                scanf("%d%d", &l, &r);
                add(in[pos[l]], l, -1);
                add(in[pos[r]], r, -1);
                swap(pos[l], pos[r]);
                add(in[pos[l]], l, 1);
                add(in[pos[r]], r, 1);
            }
            else
            {
                scanf("%s%d%d%d", s, &k, &l, &r);
                int u = qpos(s, k);
                //cout<<"qpos: "<<u<<" "<<in[u]<<" "<<out[u]<<endl;
                if (u == -1) puts("0");
                else printf("%d\n", ask(in[u] - 1, out[u], l, r));
            }
        }
    }
}trie;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        trie.insert(s, i);
    }
    trie.dfs(1);
    trie.work();
    return 0;
}
/*
3 1
aaa
bbb
aac
2 aasdd 2 1 3
*/