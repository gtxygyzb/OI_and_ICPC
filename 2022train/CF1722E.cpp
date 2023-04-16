#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;

struct Data
{
    int x, y;
    void input() {scanf("%d%d", &x, &y);}
    bool operator <(const Data &t) const {return x == t.x ? y < t.y : x < t.x;}
}a[N];

struct Tree
{
    int lc, rc;
    ll val;
    void init() {lc = rc = val = 0;}
}t[N * 30];
int top;
void add(int &u, int pre, int l, int r, int pos, ll val)
{
    if (pre != -1) t[u = ++top] = t[pre];
    if (pre == -1 && u == 0) u = ++top;
    t[u].val += val;
    //cout<<u<<" "<<l<<" "<<r<<" "<<val<<endl;
    if (l == r) return ;
    int mid = l + r >> 1;
    if (pos <= mid) add(t[u].lc, pre == -1 ? -1 : t[pre].lc, l, mid, pos, val);
    else add(t[u].rc, pre == -1 ? -1 : t[pre].rc, mid + 1, r, pos, val);
}
ll query(int u, int pre, int st, int ed, int l, int r)
{
    if (!u) return 0;
    if (st == l && ed == r)
    {
        /*cout<<"pre: "<<pre<<endl;
        cout<<l<<" "<<r<<" "<<st<<" "<<ed<<" "<<t[u].val<<" "<<t[pre].val<<endl;*/
        return t[u].val - t[pre].val;
    }
    int mid = l + r >> 1;
    ll ret = 0;
    if (st <= mid) ret += query(t[u].lc, t[pre].lc, st, min(mid, ed), l, mid);
    if (ed > mid) ret += query(t[u].rc, t[pre].rc, max(st, mid + 1), ed, mid + 1, r);
    return ret;
}

int n, q, rt[N];
void init()
{
    for (int i = 0; i <= top; i++)
        t[i].init();
    top = 0;
    for (int i = 0; i <= 1000; i++)
        rt[i] = 0;
}
int find(int k) //第一个大于等于k的位置
{
    if (a[n].x < k) return n + 1;
    int l = 1, r = n, ret = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (a[mid].x >= k) ret = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++)
            a[i].input();
        sort(a + 1, a + n + 1);
        int mx;
        for (int i = 1; i <= n; i++)
        {
            int x = a[i].x;
            int y = a[i].y;
            add(rt[i], rt[i - 1], 1, 1000, y, 1ll * x * y);
            mx = x;
        }
        for (int xq, yq, xz, yz; q--;)
        {
            scanf("%d%d%d%d", &xq, &yq, &xz, &yz);
            ++xq; ++yq;
            --xz; --yz;
            int u = find(xz + 1) - 1, pre = find(xq) - 1;
            if (u > pre && yq <= yz)
                printf("%lld\n", query(rt[u], rt[pre], yq, yz, 1, 1000));
            else puts("0");
        }
    }
    return 0;
}
/*
1
3 1
9 8
10 1
10 5

4 3 10 6
*/