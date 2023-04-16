#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int maxl=3e5+10;
 
int n,m,cnt,tot,cas,ans;
int a[maxl],ed[maxl];
bool vis[maxl];
string s[maxl];
 
int sz;
int fail[maxl],val[maxl],last[maxl];
int ch[maxl][26];
multiset<int> ms[maxl];
queue<int> q;
bool in[maxl];
 
inline void insert(int id,string s)
{
	int len=s.size(),c,u=0;
	for(int i=0;i<len;i++)
	{
		c=s[i]-'a';
		if(!ch[u][c])
		{
			sz++;
			ch[u][c]=sz;
		}
		u=ch[u][c];
	}
	ed[id]=u;val[u]++;
	ms[u].insert(0);
}
 
 
void getfail()
{
	int u,v,cur;
	while(!q.empty())
		q.pop();
	fail[0]=0;
	for(int c=0;c<26;c++)
	{
		u=ch[0][c];
		if(u) fail[u]=0,q.push(u),last[u]=0;
	}
	while(!q.empty())
	{
		cur=q.front();q.pop();
		for(int c=0;c<26;c++)
		if(ch[cur][c])
		{
			u=ch[cur][c];
			q.push(u);
			v=fail[cur];
			while(v && !ch[v][c])
				v=fail[v];
			fail[u]=ch[v][c];
			last[u]=val[fail[u]]?fail[u]:last[fail[u]];
		}
	}
}
 
inline void prework()
{
	freopen("G.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		a[i]=0;
		insert(i,s[i]);
	}
	getfail();
}
 
inline int findmx(string s)
{
	int ret=-1;
	int len=s.size(),c,j=0,jj;
	for(int i=0;i<len;i++)
	{
		c=s[i]-'a';
		while(j && !ch[j][c]) j=fail[j];
		j=ch[j][c];jj=j;
		while(jj && !in[jj])
		{
			if(val[jj])
				ret=max(ret,(*ms[jj].rbegin()));
			jj=last[jj];
		}
	}
	return ret;
}
 
inline void mainwork()
{
	string t;int op,id,x;
	for(int i=1;i<=m;i++)
	{
		cin>>op;
		if(op==1)
		{
			cin>>id>>x;
			ms[ed[id]].erase(ms[ed[id]].lower_bound(a[id]));
			a[id]=x;
			ms[ed[id]].insert(x);
		}
		else
		{
			cin>>t;
			cout<<findmx(t)<<'\n';
		}
	}
}
 
inline void print()
{
	
}
 
int main()
{
	int t=1;
	//scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		prework();
		mainwork();
		print();
	}
	return 0;
}