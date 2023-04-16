// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n,m,tot,num[N],ans[N],root[N],top;
struct Data
{
	int val,pos;
	void input(int _pos) {scanf("%d",&val); pos=_pos;}
	bool operator <(const Data &t) const {return val<t.val;}
}a[N];
struct Tree {int ls,rs,val;} t[N*20];

void build(int &u,int old,int l,int r,int pos)
{
	u=++top; t[u]=t[old]; ++t[u].val;
	if (l==r) return ;
	int mid=l+r>>1;
	if (pos<=mid) build(t[u].ls,t[old].ls,l,mid,pos);
	else build(t[u].rs,t[old].rs,mid+1,r,pos);
}
int query(int pre,int cur,int l,int r,int k)
{
	if (l==r) return l;
	int suml=t[t[cur].ls].val-t[t[pre].ls].val,mid=l+r>>1;
	int sumr=t[t[cur].rs].val-t[t[pre].rs].val;
	if (suml>=k) return query(t[pre].ls,t[cur].ls,l,mid,k);
	if (sumr>=k) return query(t[pre].rs,t[cur].rs,mid+1,r,k);
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		a[i].input(i);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		if (a[i].val!=a[i-1].val) ++tot;
		num[a[i].pos]=tot;
		ans[tot]=a[i].val;
	}
	for (int i=1;i<=n;i++)
		build(root[i],root[i-1],1,tot,num[i]);
	for (int l,r,i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",ans[query(root[l-1],root[r],1,tot,(r-l+1)/2+1)]);
	}
    return 0;
}
