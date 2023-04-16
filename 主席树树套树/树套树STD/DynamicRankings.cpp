#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 50;
int n, m, a[N];
struct Node
{
    Node *lc, *rc;
    int val;
    Node () : val(0) {lc = rc = NULL;}
};
struct Tree
{
    Node *rt;
    Tree () {rt = NULL;}
    void add(Node *&u, int l, int r, int pos, int val)
    {
        if (!u) {u = new Node();}
        u->val += val;
        if (l == r) return ;
        int mid = l + r >> 1;
        if (pos <= mid) add(u->lc, l, mid, pos, val);
        else add(u->rc, mid + 1, r, pos, val);
    }
}t[N];

int cnt[2], lsh[N], tot;
Node *rt[100][2];
void add(int x, int pos, int val)
{
    for (; x <= n; x += x & -x)
        t[x].add(t[x].rt, 1, tot, pos, val);
}

int query(int pre, int cur, int l, int r, int k)
{
    if (l == r) return l;
    int mid = l + r >> 1, sum = 0;
    for (int i = 1; i <= pre; i++)
        if (rt[i][0] && rt[i][0]->lc) sum -= rt[i][0]->lc->val;
    for (int i = 1; i <= cur; i++)
        if (rt[i][1] && rt[i][1]->lc) sum += rt[i][1]->lc->val;
    if (k <= sum)
    {
        for (int i = 1; i <= pre; i++)
            if (rt[i][0]) rt[i][0] = rt[i][0]->lc;
        for (int i = 1; i <= cur; i++)
            if (rt[i][1]) rt[i][1] = rt[i][1]->lc;
        return query(pre, cur, l, mid, k);
    }
    else
    {
        for (int i = 1; i <= pre; i++)
            if (rt[i][0]) rt[i][0] = rt[i][0]->rc;
        for (int i = 1; i <= cur; i++)
            if (rt[i][1]) rt[i][1] = rt[i][1]->rc;
        return query(pre, cur, mid + 1, r, k - sum);
    }
}
int ask(int l, int r, int k)
{
    cnt[0] = cnt[1] = 0;
    for (int i = l; i; i -= i & -i)
        rt[++cnt[0]][0] = t[i].rt;
    for (int i = r; i; i -= i & -i)
        rt[++cnt[1]][1] = t[i].rt;
    return query(cnt[0], cnt[1], 1, tot, k);
}

struct Query
{
    int opt, x, y, k;
    Query () {}
    Query (int opt, int x, int y, int k) : opt(opt), x(x), y(y), k(k) {}
}q[N];
int find(int x) {return lower_bound(lsh + 1, lsh + tot + 1, x) - lsh;}
int main()
{
    scanf("%d%d", &n, &m);
    for (int x, i = 1; i <= n; i++)
    {
        scanf("%d", a+i);
        lsh[++tot] = a[i];
    }
    char opt[10];
    for (int x, y, k, i = 1; i <= m; i++)
    {
        scanf("%s%d%d", opt, &x, &y);
        if (opt[0] == 'C')
        {
            q[i] = Query(0, x, y, -1);
            lsh[++tot] = y;
        }
        else
        {
            scanf("%d", &k);
            q[i] = Query(1, x, y, k);
        }
    }
    sort(lsh + 1, lsh + tot + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = find(a[i]);
        add(i, a[i], 1);
    }
    for (int x, i = 1; i <= m; i++)
        if (q[i].opt == 0)
        {
            x = q[i].x;
            add(x, a[x], -1);
            a[x] = find(q[i].y);
            add(x, a[x], 1);
        }
        else printf("%d\n", lsh[ask(q[i].x - 1, q[i].y, q[i].k)]);
    return 0;
}