#include <bits/stdc++.h>
using namespace std;
const int N=2e4+50,P=1e9+7,V=105;

int f[2][V][V],cnt[2][V][V];
int a[N],b[N];
int n,t,m,ans,cans;

void add(int &x,int y)
{
	x+=y;
	if (x>=P) x-=P;
}
int main()
{
	scanf("%d%d%d",&n,&t,&m);
	for (int t1,t2,i=1;i<=n;i++)
	{
		scanf("%d%d%d",&t1,b+i,&t2);
		a[i]=t1+t2;
	}
	
	memset(f[0],-0x3f,sizeof(f[0]));
	for (int u,v,i=1;i<=n;i++)
	{
		u=i&1; v=u^1;
		
		memset(cnt[u],0,sizeof(cnt[u]));
		memset(f[u],-0x3f,sizeof(f[u]));
		cnt[v][0][0]=1;
		f[v][0][0]=0;
		for (int j=0;j<=t;j++)
			for (int k=0;k<=m;k++)
			{
				f[u][j][k]=f[v][j][k];
				cnt[u][j][k]=cnt[v][j][k];
					
				if (j<a[i]||k<b[i]) continue;
				
				if (f[v][j-a[i]][k-b[i]]+1>f[u][j][k])
				{
					f[u][j][k]=f[v][j-a[i]][k-b[i]]+1;
					cnt[u][j][k]=cnt[v][j-a[i]][k-b[i]];
				}
				else if (f[v][j-a[i]][k-b[i]]+1==f[u][j][k])
					add(cnt[u][j][k],cnt[v][j-a[i]][k-b[i]]);
					
			}
	}
	
	for (int j=0;j<=t;j++)
		for (int k=0;k<=m;k++)
			ans=max(f[n&1][j][k],ans);
	for (int j=0;j<=t;j++)
		for (int k=0;k<=m;k++)
			if (f[n&1][j][k]==ans)
				add(cans,cnt[n&1][j][k]);
	printf("%d %d\n",ans,cans);
	return 0;
}
/*
3 4 4

1 4 2

2 4 1

1 4 2
*/
