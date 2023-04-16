#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
const int INF=0x3f3f3f3f;
int a[MAXN];
int dp[MAXN][MAXN];
int f[MAXN],g[MAXN],mx[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=-INF;
		}
		mx[i]=-INF;
		f[i]=g[i]=-INF;
	}
	dp[1][1]=0;
	mx[1]=0;
	f[1]=-a[1];
	g[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
			dp[i][j]=max(dp[i][j],max(a[i]+f[j],g[j]-a[i]));
			f[j]=max(f[j],mx[j]-a[i]);
			g[j]=max(g[j],a[i]+mx[j]);
			mx[j]=max(mx[j],dp[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",dp[n][i]);
	}
	return 0;
}

