// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,m,top,rt[N];
struct Tree
{
	int l,r,val;
}t[N*20];
void add(int old,int &cur,int l,int r,int val)
{
	t[cur=++top]=t[old]; ++t[cur].val;
	if (l==r) return ;
	int mid=l+r>>1;
	if (val<=mid) add(t[old].l,t[cur].l,l,mid,val);
	else add(t[old].r,t[cur].r,mid+1,r,val);
}

int query(int old,int cur,int l,int r,int st,int ed)
{
	if (st==l&&ed==r)  return t[cur].val-t[old].val;
	int mid=l+r>>1,ret=0;
	if (st<=mid) ret+=query(t[old].l,t[cur].l,l,mid,st,min(ed,mid));
	if (ed>mid) ret+=query(t[old].r,t[cur].r,mid+1,r,max(mid+1,st),ed);
	return ret;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int a,i=1;i<=n;i++)
	{
		scanf("%d",&a);
		add(rt[i-1],rt[i],0,N,a);
	}
	for (int b,x,l,r,ans,L,R;m--;)
	{
		scanf("%d%d%d%d",&b,&x,&l,&r); ans=0;
		for (int cur,i=17;~i;i--)
		{
			if (b&(1<<i)) L=ans,R=ans+(1<<i)-1,cur=0; //需要0 
			else L=ans+(1<<i),R=ans+(1<<(i+1))-1,cur=1; //需要1 
			if (!query(rt[l-1],rt[r],0,N,max(0,L-x),min(N,R-x))) cur^=1; //为0异或 
			ans+=cur<<i;
		}
		printf("%d\n",ans^b);
	}
	return 0;
}