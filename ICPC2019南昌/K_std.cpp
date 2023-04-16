#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
using namespace std;
const int maxn = 1e5 + 50;
int n, k;
vector<int> g[maxn];
int val[maxn], son[maxn], dep[maxn], sz[maxn];
int T[maxn], lc[maxn*200], rc[maxn*200], tot = 0, sum[maxn*200];
void update(int &rt, int l, int r, int pos, int x){
    if(!rt) rt = ++tot;
    sum[rt] += x;
    if(l == r) return;
    if(pos <= mid) update(lc[rt], l, mid, pos, x);
    else update(rc[rt], mid+1, r, pos, x);
}
int qry(int rt, int l, int r, int L, int R){
    if(!rt) return 0;
    if(L <= l && r <= R) return sum[rt];
    int res = 0;
    if(L <= mid) res += qry(lc[rt], l, mid, L, R);
    if(R > mid) res += qry(rc[rt], mid+1, r, L, R);
    return res;
}
ll ans = 0;
void init(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", &val[i]);
    for(int i = 2; i <= n; ++i){int u; scanf("%d", &u); g[u].push_back(i);}
}
void dfs1(int u){
    sz[u] = 1;
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        dep[v] = dep[u]+1;
        dfs1(v);  sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) son[u] = v;
    }return;
}
void del(int u){
    update(T[val[u]], 1, n, dep[u], -1);
    for(int i = 0; i < g[u].size(); ++i) del(g[u][i]);
}
void qry(int u, int td, int tv){
    int d = k+2*td-dep[u];
    d = min(d, n);//Attention!!
    int t = 2*tv-val[u];
    if(d >= 1 && t >= 0 && t <= n)  ans = ans + 2LL*qry(T[t], 1, n, 1, d);
    for(int i = 0; i < g[u].size(); ++i) qry(g[u][i], td, tv);
}
void add(int u){
    update(T[val[u]], 1, n, dep[u], 1);
    for(int i = 0; i < g[u].size(); ++i) add(g[u][i]);
}
void dfs2(int u){

    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(v == son[u]) continue;
        dfs2(v);del(v);
    }
    if(son[u]) dfs2(son[u]);
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];  if(v == son[u]) continue;
        qry(v, dep[u], val[u]);  add(v);
    }
    update(T[val[u]], 1, n, dep[u], 1);
}
int main()
{
    init();
    dep[1] = 1;
    dfs1(1);dfs2(1);
    cout<<ans<<endl;
}

