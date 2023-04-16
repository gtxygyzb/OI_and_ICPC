#include <bits/stdc++.h>
#define ls u<<1
#define rs u<<1|1
#define ps system("pause")
using namespace std;
typedef long long ll;
const int N=5e5+50;

int read()
{
	int x=0; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) ;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return x;
}
struct Edge
{
	int v,nxt;
}e[N<<2];

int etop,head[N];
void add(int u,int v)
{
	e[++etop].v=v;
	e[etop].nxt=head[u];
	head[u]=etop;
}

int in[N],out[N],tim,dep[N]={-1},dfm[N];
void init(int u,int fa)
{
	++tim; in[u]=tim;
	dfm[tim]=u;
	dep[u]=dep[fa]+1;
	for (int v,i=head[u];i;i=e[i].nxt)
	{
		v=e[i].v;
		if (v==fa) continue;
		init(v,u);
	}
	out[u]=tim;
}

int mx[N<<3],id[N<<3];
void change(int u,int l,int r,int pos,int val)
{
	if (l==r) {mx[u]=val; id[u]= (val==-1 ? 0 : pos); return ;}
	int mid=l+r>>1;
	if (pos<=mid) change(ls,l,mid,pos,val);
	else change(rs,mid+1,r,pos,val);
	
	mx[u]=-1; id[u]=0;
	if (mx[ls]>mx[rs])
		mx[u]=mx[ls],id[u]=id[ls];
	else
		mx[u]=mx[rs],id[u]=id[rs];
}
int query(int u,int st,int ed,int l,int r) //返回最大值点dfn序 
{
	if (st==l&&ed==r) return id[u];
	int mid=l+r>>1,rmx=-1,rid=0,upos;
	if (st<=mid)
	{
		upos=query(ls,st,min(ed,mid),l,mid);
		if (dep[dfm[upos]]>rmx) rmx=dep[dfm[upos]],rid=upos;
	}
		
	if (ed>mid)
	{
		upos=query(rs,max(st,mid+1),ed,mid+1,r);
		if (dep[dfm[upos]]>rmx) rmx=dep[dfm[upos]],rid=upos;
	}
	return rid;
}

int n,m;
bool b[N<<1];
ll ans;

void dfs(int u,int fa)
{
	for (int v,i=head[u];i;i=e[i].nxt)
	{
		v=e[i].v;
		if (v==fa) continue;
		dfs(v,u);
	}
	int pos=dfm[query(1,in[u],out[u],1,n)];
	if (pos&&pos!=u) //说明有更深的点 
	{
		if (b[u]==0) //当前点空 
		{
			ans-=dep[pos]-dep[u]; //将底下这点移到该位置，更新答案 
			b[pos]=0; b[u]=1;
			change(1,1,n,in[pos],-1); //底下的点删除
			change(1,1,n,in[u],dep[u]); //该点有值 
		}
	}
}

int main()
{
	memset(mx,-1,sizeof(mx));
	n=read(); m=read();
	for (int u,v,i=1;i<n;i++)
	{
		u=read(); v=read();
		add(u,v); add(v,u);
	}
	init(1,0);
	for (int pos,i=1;i<=m;i++)
	{
		pos=read(); b[pos]=1;
		change(1,1,n,in[pos],dep[pos]); //dfn序线段树 
		ans+=dep[pos];
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
