#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pa;
const int N = 2e6 + 50;
int n, a[N];
namespace Seg
{
    #define lc (u << 1)
    #define rc (u << 1 | 1)
    ll sum[N], mx[N], lazy[N];
    void tag(int u, int siz, int val)
    {
        sum[u] = 1ll * siz * val;
        lazy[u] = val;
        mx[u] = val;
    }
    void pu(int u)
    {
        sum[u] = sum[lc] + sum[rc];
        mx[u] = max(mx[lc], mx[rc]);
    }
    void pd(int u, int l, int r)
    {
        if (!lazy[u]) return ;
        int mid = l + r >> 1;
        tag(lc, mid - l + 1, lazy[u]);
        tag(rc, r - mid, lazy[u]);
        lazy[u] = 0;
    }
    void init()
    {
        for (int i = 1; i <= 4 * n; i++)
            sum[i] = mx[i] = 0;
    }
    void change(int u, int st, int ed, int l, int r, int val)
    {
        if (st == l && ed == r) {tag(u, r - l + 1, val); return ;}
        pd(u, l, r);
        int mid = l + r >> 1;
        if (st <= mid) change(lc, st, min(mid, ed), l , mid, val);
        if (ed > mid) change(rc, max(st, mid + 1), ed, mid + 1, r, val);
        pu(u);
    }
    ll query(int u, int st, int ed, int l, int r)
    {
        if (st == l && ed == r) return sum[u];
        ll ret = 0; int mid = l + r >> 1;
        pd(u, l, r);
        if (st <= mid) ret += query(lc, st, min(mid, ed), l , mid);
        if (ed > mid) ret += query(rc, max(st, mid + 1), ed, mid + 1, r);
        return ret;
    }
    int find(int u, int l, int r, int val) //第一个小于等于val的位置
    {
        if (l == r) return l;
        int mid = l + r >> 1;
        pd(u, l, r);
        if (mx[lc] <= val) return find(lc, l, mid, val);
        else return find(rc, mid + 1, r, val);
    }
}
int fa[N], mx[N], pos[N], last, top;
int t[N], rk[N], cnt[N];
ll ans = 0;
map <int, int> ch[N];
void add(int c, int id)
{
    int p = last, np = last = ++top;
    mx[np] = mx[p] + 1;
    pos[np] = id; cnt[np] = 1;
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
            ch[nq] = ch[q];
            for (; ch[p][c] == q; p = fa[p])
                ch[p][c] = nq;
        }
    }
}
vector <pa> vec[N];
void merge()
{
    for (int i = 1; i <= top; i++) ++t[mx[i]];
    for (int i = 1; i <= top; i++) t[i] += t[i - 1];
    for (int i = top; i >= 1; i--) rk[t[mx[i]]--] = i;
    for (int i = top; i >= 2; i--)
    {
        int u = rk[i];
        //cout<<"edge:"<<u<<" "<<fa[u]<<" "<<cnt[u]<<endl;
        cnt[fa[u]] += cnt[u];
        pos[fa[u]] = max(pos[fa[u]], pos[u]);
    }
    for (int i = top; i >= 2; i--)
    {
        int u = rk[i];
        //cout<<u<<" "<<fa[u]<<" :"<<mx[u]<<" "<<cnt[u]<<" "<<pos[u]<<endl;
        vec[pos[u]].push_back(pa(mx[u], 1));
        vec[pos[u]].push_back(pa(mx[fa[u]], -1));
    }
}
void init()
{
    last = top = 1;
    for (int i = 1; i <= n + n; i++)
    {
        ch[i].clear();
        vec[i].clear();
        Seg::init();
        rk[i] = t[i] = cnt[i] = fa[i] = mx[i] = 0;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            add(a[i], i);
        }
        merge();
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                Seg::change(1, 1, 1, 1, n, a[1]);
            else
            {
                int pos = Seg::find(1, 1, n, a[i]);
                Seg::change(1, pos, i, 1, n, a[i]);
            }
            for (int j = 0; j < vec[i].size(); j++)
            {
                int l = i - vec[i][j].first + 1, x = vec[i][j].second;
                ans += Seg::query(1, l, i, 1, n) * x;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
1
3
5 1 1 
*/