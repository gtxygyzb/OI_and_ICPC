#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 1e5 + 50;
int top, tot, a[maxn],b[maxn],anc[maxn][20],in[maxn],out[maxn],rt[maxn], dfm[maxn];
int bin[20] = {1};
struct node{
    int l,r;
    int sum;
}t[maxn*40];
void add(int &u,int pre,int l,int r,int pos){
    t[u=++top]=t[pre]; ++t[u].sum;
	if (l==r) return ;
	int mid=l+r>>1;
	if (pos<=mid) add(t[u].l,t[pre].l,l,mid,pos);
	else add(t[u].r,t[pre].r,mid+1,r,pos);
}
int query(int l,int r,int old,int now,int nl,int nr){
    if(nl==l&&nr==r){
        return t[now].sum-t[old].sum;
    }
    int mid=(l+r)>>1;
    if(nr<=mid) return query(l,mid,t[old].l,t[now].l,nl,nr);
    if (nl>mid) return query(mid+1,r,t[old].r,t[now].r,nl,nr);

    return query(l,mid,t[old].l,t[now].l,nl,mid)+query(mid+1,r,t[old].r,t[now].r,mid+1,nr);
}
vector <int> g[maxn];
void dfs(int x,int f)
{
    for (int i=1;i<=17;i++)
		anc[x][i]=anc[anc[x][i-1]][i-1];
    ++tot; 
    in[x]=tot;
    dfm[tot] = x;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (y==f) continue ;
        anc[y][0]=x;
        dfs(y,x);
    }
    out[x]=tot;
}
int main()
{
    int n,u,v,T;
    for (int i = 1; i <= 17; i++)
        bin[i] = bin[i-1] << 1;
    scanf("%d",&n);
    for (int i=1;i<n;i++) {
        scanf("%d%d",&u,&v);
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        add(rt[i],rt[i-1],1,1e9,a[dfm[i]]);
    scanf("%d",&T);
    for (int i=1;i<=T;i++) {
        int x,l,r;
        scanf("%d%d%d",&x,&l,&r);
        if (a[x]<l||a[x]>r) {printf("0\n"); continue ;}
        for (int j=17;j>=0;j--) {
            if (anc[x][j]&&a[anc[x][j]]<=r) x=anc[x][j];
        }
        int ql=l; int qr=r;
        l=in[x]; r=out[x];
        int ans=query(1,1e9,rt[l-1],rt[r],ql,qr);
        printf("%d\n",ans);
    }
    return 0;
}
/*
4
1 2
1 3
2 4
10 8 7 6
3
1 10 10
2 6 7
3 7 10
*/