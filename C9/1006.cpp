#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50, m = 2e5;

struct Seg
{
    #defing lc u<<1
    #defing rc u<<1|1
    ll cnt[N<<2], sc[N<<2], s[N<<2], tag[N<<2]; // 0不乘cnt 1乘cnt
    void init()
    {
        memset(cnt, 0 , sizeof(cnt));
        memset(s, 0 , sizeof(s));
        memset(tag, 0 , sizeof(tag));
    }
    void pd(int u)
    {

    }
    void add(int u, int st, int ed, int l, int r, int val)
    {
        if (st == l && ed == r)
        {
            sum[u] += 1LL * (r - l + 1) + val;
            tag[u] += val;
            return ;
        }
        pd(u); int mid = l + r >> 1;
        if (st <= mid) add(lc, st, min(mid, ed), l, mid, val);
	    if (ed > mid) add(rc, max(mid+1, st), ed, mid+1, r, val);
        s[u] = s[lc] + s[rc];
    }
    void add(int l, int r, int val)
    {
        if (l > r) return ;
        add(1, l, r, 1, m, val);
    }
    void modify
    void c(int x, int val) {modify(1, 1, m, x, val);}
    ll query(int u, int st, int ed, int l, int r, int opt)
    {
        if st == l && ed == r
    }
    ll query(int l, int r, int opt)
    {
        if (l > r) return 0;
        return query(1, l, r, 1, m, opt);
    }
}t[2]; //0min 1max

void init()
{
    t[0].init();
    t[1].init();
}
int find(int l, int r)
{
    
}
void work()
{
    ll sum = 0;
    int n, q;
    scanf("%d%d", &n, &q);
    for (int w, i = 1; i <= n; i++)
    {
        scanf("%d", &w);
        t[0].add(w + 1, m, 1);
        t[1].add(1, w - 1, 1);
        t[0].c(w, 1);
        t[1].c(w, 1);
    }
    sum = n;
    for (int opt, x, w; q--;)
    {
        scanf("%d", &opt);
        if (opt == 1)
        {
            scanf("%d%d", &x, &w); // 加入x张费用为w的卡
            sum += x;
            t[0].add(w + 1, m, x);
            t[1].add(1, w - 1, x);
            t[0].c(w, x); //改cnt
            t[1].c(w, x);
        }
        else
        {
            int pos = find(1, m); //1-pos用比他大的，pos+1到m找比他小的
            ll x = t[1].query(1, pos, 1) + t[0].query(pos + 1, m, 1);
            ll y = sum * (sum - 1);
            ll g = __gcd(x, y);
            printf("%lld/lld\n", x / g, y / g);
        }
    }
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