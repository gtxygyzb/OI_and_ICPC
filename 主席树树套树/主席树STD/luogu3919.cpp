#include <bits/stdc++.h>
using namespace std;
const int N=1e6+50,L=30;
int a[N ],n,m,tim,top,root[N];
struct Tree
{
	int ls,rs,val;
}t[N * L];
void build(int &u,int l,int r)
{
	u=++top;
	if (l==r) {t[u].val=a[l]; return ;}
	int mid=l+r>>1;
	build(t[u].ls,l,mid);
	build(t[u].rs,mid+1,r);
}
void change(int &cur,int pre,int l,int r,int pos,int val)
{
	t[cur=++top]=t[pre];
	if (l==r) {t[cur].val=val; return ;}
	int mid=l+r>>1;
	if (pos<=mid) change(t[cur].ls,t[pre].ls,l,mid,pos,val);
	else change(t[cur].rs,t[pre].rs,mid+1,r,pos,val);
}
int query(int u,int l,int r,int pos)
{
	if (l==r) return t[u].val;
	int mid=l+r>>1;
	if (pos<=mid) return query(t[u].ls,l,mid,pos);
	else return query(t[u].rs,mid+1,r,pos);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(root[tim],1,n);
	for (int ti,opt,pos,val;m--;)
	{
		scanf("%d%d%d",&ti,&opt,&pos);
		if (opt==1)
		{
			scanf("%d",&val);
			change(root[++tim],root[ti],1,n,pos,val);
		}
		else printf("%d\n",query(root[++tim]=root[ti],1,n,pos));
	}
	return 0;
}
