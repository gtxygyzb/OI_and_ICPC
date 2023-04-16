#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50, inf = 0x3f3f3f3f;
char s[N], t[N];
int n, m, ans, a[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		scanf("%s%s", s, t);
		ans = inf;
		for (int i = m; ~i; i--)
		{
			int ps = n - 1, pt = m - 1, tot = 0, flag = 1;
			while (pt >= i)
			{
				while (ps >= 0 && s[ps] != t[pt])
					a[ps--] = -1;
				if (ps < 0) {flag = 0; break;}
				a[ps--] = ++tot;
				--pt;
			}
			if (pt != i - 1 || !flag) continue;
			
			int rlim = ps;
			ps = 0; pt = 0;
			while (pt <= i - 1)
			{
				while (ps <= rlim && s[ps] != t[pt])
					a[ps++] = -2;
				if (ps > rlim) {flag = 0; break;}
				a[ps++] = ++tot;
				++pt;
			}
			if (pt != i || !flag) continue;
			int ck = 0; //是否存在中间的点 
			for (int j = ps; j <= rlim; j++) //中间的点可能给左边也可能给右边 
				{a[j] = -3; ck = 1;}
			
			/*cout<<i<<":\n";
			for (int j = 0; j <n; j++)
				cout<<a[j]<<" ";
			puts("");*/
			
			/*if (i == 0) //全是从右边匹配的需要特判 
			{
				int u = 0;
				while (a[u] > 0 && u <= n - 1) ++u; //第一个要删的位置
				ans = min(ans, n - u);
				cout<<"te:"<<n - u<<endl;
				continue;
			}*/
			
			int st;
			for (int j = 0; j < n; j++) //找到最后一个匹配的位置 
				if (a[j] == m) {st = j; break;}
			if (i == 0) st = -1;
			//中间的点给右边
			tot = 0; 
			int u = st;
			while (u >= 0 && a[u] != -2) --u; //最后一个-2的位置 
			if (u >= 0) ++tot; //如果不是全匹配，需要home键+1次 
			while (u >= 0) //统计左边的次数 
			{
				if (a[u] == -2) tot += 2;
				else ++tot;
				--u;
			}
			u = st + 1;
			while (u <= n - 1 && a[u] > 0) ++u; //右边第一个需要删的位置
			ans = min(ans, tot + n - u);
			//cout<<"you: "<< tot + n - u<<endl;
			
			//中间的点给左边，如果不存在中间的点，则上文中间的点给右边就是答案 
			if (ck) 
			{
				tot = 1; //home键一次 
				for (int j = 0; j <= st; j++)
					if (a[j] == -2) tot += 2;
					else ++tot;
				u = st + 1;
				while (a[u] == -3 && u <= n - 1) {tot += 2; ++u;}
				while (a[u] > 0 && u <= n - 1) ++u; //第一个需要删的位置
				//cout<<"zuo:"<<tot + n - u<<endl;
				ans = min(ans, tot + n - u);	
			}
		}
		printf("%d\n", ans == inf ? -1 : ans);
	}
	return 0;
}
/*
1
10 8
aaabaabbbb
aabaabbb
*/
