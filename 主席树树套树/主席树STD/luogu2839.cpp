// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
const int N=5e4+50,inf=0x3f3f3f3f;
int n,top,root[N],q[4];

struct Tree
{
	int ls,rs,lmax,rmax,sum;
}t[N*20];

void pu(int u)
{
	int l=t[u].ls,r=t[u].rs;
	t[u].sum=t[l].sum+t[r].sum;
	t[u].lmax=max( t[l].lmax, t[l].sum+t[r].lmax );
	t[u].rmax=max( t[r].rmax, t[r].sum+t[l].rmax );
}
void build(int &u,int l,int r)
{
	u=++top;
	if (l==r)
	{
		t[u].sum=t[u].lmax=t[u].rmax=1;
		return ;
	}
	int mid=l+r>>1;
	build(t[u].ls,l,mid);
	build(t[u].rs,mid+1,r);
	pu(u);
}
void change(int &u,int old,int l,int r,int pos)
{
	u=++top; t[u]=t[old];
	if (l==r)
	{
		t[u].sum=t[u].lmax=t[u].rmax=-1;
		return ;
	}
	int mid=l+r>>1;
	if (pos<=mid) change(t[u].ls,t[old].ls,l,mid,pos);
	else change(t[u].rs,t[old].rs,mid+1,r,pos);
	pu(u);
}

int query_sum(int u,int st,int ed,int l,int r)
{
	if (st>ed) return 0;
	if (st==l&&ed==r) return t[u].sum;
	int mid=l+r>>1,ret=0;
	if (st<=mid) ret+=query_sum(t[u].ls,st,min(ed,mid),l,mid);
	if (ed>mid) ret+=query_sum(t[u].rs,max(mid+1,st),ed,mid+1,r);
	return ret;
}
int query_right(int u,int st,int ed,int l,int r)
{
	if (st==l&&ed==r) return t[u].rmax;
	int mid=l+r>>1,ret=-inf;
	if (ed>mid) ret=max(ret, query_right(t[u].rs,max(st,mid+1),ed,mid+1,r) );
	
	if (st<=mid) ret=max(ret, query_sum(t[u].rs,mid+1,ed,mid+1,r)
							 +query_right(t[u].ls,st,min(mid,ed),l,mid) );
	return ret;
}
int query_left(int u,int st,int ed,int l,int r)
{
	if (st==l&&ed==r) return t[u].lmax;
	int mid=l+r>>1,ret=-inf;
	if (st<=mid) ret=max(ret, query_left(t[u].ls,st,min(ed,mid),l,mid) );
	if (ed>mid) ret=max(ret, query_sum(t[u].ls,st,mid,l,mid)
							+query_left(t[u].rs,max(st,mid+1),ed,mid+1,r) );
	return ret;
}

int check(int mid)
{
	int ret=0;
	ret+=query_sum(root[mid],q[1]+1,q[2]-1,0,n-1);
	ret+=query_right(root[mid],q[0],q[1],0,n-1);
	ret+=query_left(root[mid],q[2],q[3],0,n-1);
	return ret>=0;
}

pair <int,int> a[N];
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a,a+n);
	t[0].lmax=t[0].rmax=-inf;
	build(root[0],0,n-1);
	for (int i=0;i<n;i++)
		change(root[i+1],root[i],0,n-1,a[i].second);
	int m,last=0;
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		for (int i=0;i<4;i++)
		{
			scanf("%d",q+i);
			q[i]=(q[i]+last)%n;
		}
		sort(q,q+4);
		int l=0,r=n-1;
		while (l<r)
		{
			int mid=l+r+1>>1;
			if (check(mid)) l=mid;
			else r=mid-1;
		}
		printf("%d\n",last=a[l].first);
	}
    return 0;
}
