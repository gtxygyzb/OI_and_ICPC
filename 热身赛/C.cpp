#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 50, L = 18;
int n, a[N], f[N][N], lo[N] = {-1}, bin[L] = {1};
int xiao[N][L], da[N][L];
int qmax(int l, int r)
{
	int len = lo[r - l + 1] ;
	return max(da[l][len], da[r - bin[len] + 1][len]);
}
int qmin(int l, int r)
{
	int len = lo[r - l + 1] ;
	return min(xiao[l][len], xiao[r - bin[len] + 1][len]);
}
int dp(int k, int i, int j)
{
	//cout<<k + 1<<" "<<i<<" "<<qmax(k + 1, i)<<" "<<qmin(k + 1, i)<<endl;
	return f[k][j] + qmax(k + 1, i) - qmin(k + 1, i);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < L; i++)
		bin[i] = bin[i - 1] << 1;
	for (int i = 1; i <= n; i++)
	{
		lo[i] = lo[i >> 1] + 1;
		scanf("%d", a+i);
		da[i][0] = xiao[i][0] = a[i];
	}
	for (int j = 1; bin[j] <= n; j++)
		for (int i = 1; i + bin[j] - 1 <= n; i++)
		{
			da[i][j] = max(da[i][j - 1], da[i + bin[j - 1]][j - 1]);
			xiao[i][j] = min(xiao[i][j - 1], xiao[i + bin[j - 1]][j - 1]);
		}
		
	for (int i = 1; i <= n; i++)
		f[i][1] = qmax(1, i) - qmin(1, i);
	for (int j = 2; j <= n; j++)
	{
		int k = j - 1;
		for (int i = j; i <= n; i++)
		{
			while (k < i - 1 && (dp(k, i, j - 1) <= dp(k + 1, i, j - 1) || dp(k, i, j - 1) <= dp(i - 2, i, j - 1))) ++k;
			f[i][j] = dp(k, i, j - 1);
			cout<<i<<" "<<j<<"f: "<<f[i][j]<<" <- "<<k<<" "<<j - 1<<endl;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", f[n][i]);
	puts("---------------");
	memset(f, -0x3f, sizeof(f));
	f[0][0] = 0;
	for (int j = 1; j <= n; j++)
		for (int i = j; i <= n; i++)	
		{
			int a1, a2;
			for (int k = 0; k < i; k++)
			{
				if (f[k][j - 1] < 0) continue;
				int mi = 1e9, mx = 0;
				for (int l = k + 1; l <= i; l++)
				{
					mi = min(mi, a[l]);
					mx = max(mx, a[l]);
				}
				
				if (f[k][j - 1] + mx - mi >= f[i][j])
				{
					a1 = k; a2 = j - 1;
					f[i][j] = max(f[i][j], f[k][j - 1] + mx - mi);
				}
			}
			cout<<i<<" "<<j<<"f: "<<f[i][j]<<" <- "<<a1<<" "<<a2<<" f:"<<f[a1][a2]<<endl;
		}
	for (int i = 1; i <= n; i++)
		printf("%d\n", f[n][i]);
	return 0;
}
/*
20
7 8 5 4 1 2 6 5 8 9 7 4 5 6 3 2 1 2 5 9

10
8 7 4 5 9 1 2 3 6 10
*/

