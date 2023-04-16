#include <bits/stdc++.h>
using namespace std;
const int N = 40, S = 1 << 19;
int n, m, mp[N][N];
int w[N], c[N], cnt[N];

int f[S][N], bin[N], b[N];

void cmax(int &x, int y) {if (y < 0) return ; x = max(x, y);}
int main()
{
	bin[0] = 1;
	for (int i = 1; i <= 19; i++)
		bin[i] = bin[i - 1] << 1;
		
	scanf("%d%d", &n, &m);
	for (int i = 1; i<= n; i++)
	{
		scanf("%d", c+i);
		++cnt[c[i]];
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", w+i);
	for (int u, v, i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		mp[u][v] = 1;
	}
	
	int s = 0;
	for (int i = 1; i <= n; i++)
		if (cnt[i] >= 2) b[i] = s++; //第i家公司是第几位 
	 for (int i = 1; i <= n; ++i)
         for (int j = i + 1; j <= n; ++j)
             for (int k = i + 1; k <= j; ++k)
                 if (mp[i][j] && mp[i][k] && mp[k][j] )
                     mp[i][j] = 0;
	
	memset(f, -0x3f, sizeof(f));
	if (cnt[c[1]] == 1) f[0][1] = w[c[1]];
	else f[bin[b[c[1]]]][1] = w[c[1]];
	
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
		{
			if (!mp[j][i]) continue;
			for (int u = 0; u < bin[s]; u++)
			{
				if (cnt[c[i]] == 1) //只出现一次，那就直接加上去
					cmax(f[u][i], f[u][j] + w[c[i]]);
				else
				{
					int bi = b[c[i]];
					//cout<<"bi:"<<bi<<endl;
					if (u & bin[bi])
					{
						//cout<<u<<" "<<j<<" "<<" "<<f[u][j]<<endl;
						cmax(f[u][i], f[u][j]); //之前已经选过了
						cmax(f[u][i], f[u ^ bin[bi]][j] + w[c[i]]);
					}
					else cmax(f[u][i], f[u][j]);
				}
			}
		}
	for (int i = 1; i <= n; i++)
	{
		int ans = -1e9;
		for (int u = 0; u < bin[s]; u++)
			ans = max(ans, f[u][i]);
		printf("%d\n", ans);
	}
	return 0;
}
/*
3 2
1 1 1
1 2 3
1 2
2 3
*/
