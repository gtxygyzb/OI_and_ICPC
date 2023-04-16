#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50, P = 998244353;
int bin[50] = {1}, n, tot, t[N];

struct Tree
{
    #define lc u<<1
    #define rc u<<1|1
    int sum[N<<2], mx[N<<2], tag[N<<2];
    void pu(int u)
    {
        sum[u] = (sum[lc] + sum[rc])%P;
        mx[u] = max(mx[lc], mx[rc]);
    }
    void build(int u, int l, int r, int *a, int val)
    {
        tag[u] = val;
        if (l == r) {sum[u] = mx[u] = a[l]; return ;}
        int mid = l + r >> 1;
        build(u<<1, l, mid, a, val);
        build(u<<1|1, mid + 1, r, a, val);
        pu(u);
    }
    void lowbit(int u, int st, int ed, int l, int r)
    {
        if (mx[u] == 0) return ;
        if (l == r)
        {
            sum[u] -= sum[u] & -sum[u];
            mx[u] = sum[u];
            return ;
        }
        int mid = l + r >> 1;
        if (st <= mid) lowbit(u<<1, st, min(mid,ed), l, mid);
        if (ed > mid) lowbit(u<<1|1, max(mid+1,st), ed, mid+1, r);
        pu(u);
    }
    void del(int u, int st, int ed, int l, int r)
    {
        if (mx[u] == 0) return ;
        if (l == r)
        {
            --mx[u];
            if (mx[u] == 0)
                t[++tot] = l;
            return ;
        }
        int mid = l + r >> 1;
        if (st <= mid) del(u<<1, st, min(mid,ed), l, mid);
        if (ed > mid) del(u<<1|1, max(mid+1,st), ed, mid+1, r);
        pu(u);
    }
    int query(int u, int st, int ed, int l, int r)
    {
        if (st == l && ed == r) return sum[u] % P;
        pd(u);
        int mid = l + r >> 1, ret = 0;
        if (st <= mid) ret = (ret + query(u<<1, st, min(mid,ed), l, mid)) %P;
	    if (ed > mid) ret = (ret + query(u<<1|1, max(mid+1,st), ed, mid+1, r)) %P;
        return ret;
    }
    void modify(int u, int l, int r, int pos)
    {
        if (l == r) {sum[u] = mx[u] = 0; return ;}
        int mid = l + r >> 1;
        pd(u);
        if (pos <= mid) modify(u<<1, l, mid, pos);
        else modify(u<<1|1, mid + 1, r, pos);
        pu(u);
    }
    void ptag(int u, int t)
    {
        tag[u]= 1LL * tag[u] * t % P;
	    sum[u]= 1LL * sum[u] * t % P;
    }
    void pd(int u)
    {
        if (tag[u] > 1)
        {
            ptag(lc, tag[u]);
            ptag(rc, tag[u]);
            tag[u] = 1;
        }
    }
    void mul(int u, int st, int ed, int l, int r)
    {
        if (st == l && ed == r)
        {
            tag[u] = 1LL * tag[u] * 2 % P;
            sum[u] = 1LL * sum[u] * 2 % P;
            return ;
        }
        pd(u);
        int mid=l+r>>1;
        if (st<=mid) mul(u<<1, st, min(mid,ed), l, mid);
        if (ed>mid) mul(u<<1|1, max(mid+1,st), ed, mid+1, r);
        pu(u);
    }
    void del(int l, int r) {del(1, l, r, 1, n);}
    void lowbit(int l, int r) {lowbit(1, l, r, 1, n);}
    void mul(int l, int r) {mul(1, l, r, 1, n);}
    int query(int l, int r) {return query(1, l, r, 1, n);}
}t1, t2, t3; // lowbit 1cnt mul

int a[N], b[N], c[N];

int count(int x)
{
    int ret = 0;
    while (x)
    {
        x -= x & -x;
        ++ret;
    }
    return ret;
}
void work()
{
    int m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    memcpy(b, a, sizeof(int) * (n+5));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 30; j >= 0; j--)
            if (a[i] & bin[j])
            {
                b[i] = count(a[i]);
                a[i] -= bin[j];
                c[i] = bin[j];
                break;
            }
    }
    t1.build(1, 1, n, a, 0);
    t2.build(1, 1, n, b, 0);
    t3.build(1, 1, n, c, 1);
    scanf("%d", &m);
    for (int opt, l, r; m--; )
    {
        scanf("%d%d%d", &opt, &l, &r);
        if (opt == 1)
            printf("%d\n", (t1.query(l, r)+ t3.query(l, r))%P);
        if (opt == 2)
        {
            tot = 0;
            t1.lowbit(l, r);
            t2.del(l, r);
            for (int i = 1; i <= tot; i++)
                t3.modify(1, 1, n, t[i]);
        }
        if (opt == 3)
            t3.mul(l, r);
        /*l = 1, r=n;
        printf("%d %d %d\n", t1.query(l, r), t3.query(l, r), (t1.query(l, r)+ t3.query(l, r))%P);*/
    }
}
int main()
{
    for (int i = 1; i <= 30; i++)
        bin[i] = bin[i-1] << 1;
    int T;
    scanf("%d", &T);
    while (T--)
        work();
    return 0;
}
/*
1
9
821 666 805 196 501 955 633 95 736
5
2 1 9
3 3 7
3 7 9
2 1 7
2 1 6
*/