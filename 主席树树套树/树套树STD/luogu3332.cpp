#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5 + 50;
int n,m,root[N],top;
struct Tree
{
    int l,r;
    ll lazy,sum;
}t[N*20];
void segadd(int &u,int st,int ed,int l,int r)
{
    if (!u) u=++top;
    if (st==l&&ed==r)
    {
        t[u].sum+=ll(ed-st+1);
        t[u].lazy++;
        return ;
    }
    int mid=l+r>>1;
    if (st<=mid) segadd(t[u].l,st,min(ed,mid),l,mid);
    if (ed>mid) segadd(t[u].r,max(mid+1,st),ed,mid+1,r);
    int ls=t[u].l,rs=t[u].r;
    t[u].sum=t[ls].sum+t[rs].sum+(ll)t[u].lazy*(r-l+1);
}
void add(int l,int r,int pos)
{
    int L=0,R=n,u=1;
    while (L<=R)
    {
        segadd(root[u],l,r,1,n);
        if (L==R) return ;
        int mid=L+R>>1;
        if (pos<=mid) R=mid,u=u<<1;
        else L=mid+1,u=u<<1|1;
    }
}
ll segquery(int u,int st,int ed,int l,int r)
{
    if (!u) return 0;
    if (st==l&&ed==r)
        return t[u].sum;
    int mid=l+r>>1;
    ll ans=t[u].lazy*(ll)(ed-st+1);
    if (st<=mid) ans+=segquery(t[u].l,st,min(ed,mid),l,mid);
    if (ed>mid) ans+=segquery(t[u].r,max(mid+1,st),ed,mid+1,r);
    return ans;
}
int query(int l,int r,ll k)
{
    int L=0,R=n,u=1;
    do
    {
        ll tmp=segquery(root[u<<1|1],l,r,1,n);
        int mid=L+R>>1;
        if (k<=tmp) L=mid+1,u=u<<1|1;
        else R=mid,u=u<<1,k-=tmp;
    }while (L<R);
    return L;
}
int main()
{
    ll val;
    scanf("%d%d",&n,&m);
    for (int opt,l,r,i=1;i<=m;i++)
    {
        scanf("%d%d%d%lld",&opt,&l,&r,&val);
        if (opt==1) add(l,r,val);
        else printf("%d\n",query(l,r,val));
    }
    return 0;
}