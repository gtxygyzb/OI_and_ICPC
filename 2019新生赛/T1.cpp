#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],f[N][N],sum[N][N],ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			sum[i][j]=a[j]^sum[i][j-1];
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			for (int k=0;k<i;k++)
				f[i][j]=max(f[i][j],f[k][j-1]+sum[k+1][i]);
	for (int j=1;j<=n;j++)
		ans=max(ans,f[n][j]);
	cout<<ans;
	return 0;
}
/*
5
1 2 3 6 4
*/
