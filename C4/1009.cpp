#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 50;

int n, m, k;
struct Point
{
    int x, y;
    bool operator <(const Point &p) const
    {
        return x == p.x ? y < p.y : x < p.x; 
    }
    void input()
    {
        scanf("%d%d", &x, &y);
    }
}p[N];

struct Seg
{
    int t[N], lazy[N];

    void pd(int u, int l, int mid, int r)
    {
        if (lazy[u] != 0)
        {
            t[u<<1] = t[u<<1|1] = 0;
            lazy[u<<1] = lazy[u<<1|1] = lazy[u];
            if (lazy[u] == 1)
            {
                t[u<<1] = mid - l + 1;
                t[u<<1|1] = r - mid + 1;
            }
            lazy[u] = 0;
        }
    }
    int query(int u, int st, int ed, int l, int r)
    {
        if (st == l && ed == r)
            return t[u];
        int ret = 0, mid = l + r >> 1;
        pd(u, l, mid, r);
        if (st <= mid) ret += query(u<<1, st, min(mid, ed), l ,mid);
        if (ed > mid) ret += query(u<<1|1, max(st, mid+1), ed, mid+1 ,r);
        return ret;
    }
    int ask(int u, int st, int ed, int l, int r)
    {
        if (st == ed)
            return st;
        if (t[u] == ed - st + 1) return -1;
        int mid = l + r >> 1, ret = 0;
        pd(u, l, mid, r);
        if (st == l)
        {
            if (t[u] < r - l + 1)
                ret = ask(u<<1, st, min(mid, ed), l ,mid);
            else ret = ask(u<<1|1, max(st, mid+1), ed, mid+1 ,r);
        }
        else
        {
            if (st <= mid) ret = ask(u<<1, st, min(mid, ed), l ,mid);
            if (ed > mid || ret <= 0) ret = ask(u<<1|1, max(st, mid+1), ed, mid+1 ,r);
        }
        return ret;
    }
    /*int ask(int u, int st, int ed, int l, int r) //求st到ed第一个0的位置
    {
        if (query(1, st, ed, 1, m) == ed - st + 1)
            return -1;
        while (st < ed)
        {
            int mid = st + ed >> 1;
            if (query(1, st, mid, 1, m) < mid - st + 1)
                ed = mid;
            else st = mid + 1;
        }
    }*/
    int ask(int st, int ed)
    {
        if (st > ed) return -1;
        return ask(1, st, ed, 1, m);
    }
    void modify(int u, int st, int ed, int l, int r, int val)
    {
        if (st == l && ed == r)
        {
            t[u] = (r - l + 1) * val;
            lazy[u] = val;
            if (val == 0) lazy[u] = -1;
            return ;
        }
        int mid = l + r >> 1;
        pd(u, l, mid, r);
        if (st <= mid) modify(u<<1, st, min(mid, ed), l ,mid, val);
        if (ed > mid) modify(u<<1|1, max(st, mid+1), ed, mid + 1, r, val);
        t[u] = t[u<<1] + t[u<<1|1];
    }
    void modify(int st, int ed)
    {
        st += (st == 0);
        if (st > ed) return ;
        modify(1, st, ed, 1, m, 1);
    }
    void clear(int siz)
    {
        modify(1, 1, siz, 1, siz, 0);
    }
}seg[2];
ll ans;
void init()
{
    ans = 0;
}

int h[N], siz;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= k; i++)
            p[i].input();
        sort(p+1, p+k+1);
        seg[1].clear(m);
        if (p[1].x == 1)
            seg[1].modify(p[1].y, m);
        // cout<<"fsda:"<<seg[1].query(1, 3, 5, 1, m)<<endl;
        ans += m - seg[1].t[1];
        int kt = 1;
        for (int i = 2; i <= n; i++)
        {
            int u = i & 1, v = !(i & 1);
            seg[u].clear(m);
            while (p[kt].x < i) ++kt;
            siz = 1;
            h[siz] = 0;
            while (p[kt].x == i) h[++siz] = p[kt++].y;
            h[++siz] = m + 1;
            for (int pos, j = 1; j < siz; j++)
            {
                pos = seg[v].ask(h[j] + 1, h[j+1] - 1);  //两点之间第一个0的位置
                printf("%d pos:%d\n", i, pos);
                if (pos == -1) // 没有0
                    seg[u].modify(h[j], h[j+1] - 1);
                else
                    seg[u].modify(h[j], pos - 1);
            }
            ans += m - seg[u].t[1];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
1
2 5 2
1 3
2 2
*/