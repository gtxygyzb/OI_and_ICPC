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
			int ck = 0; //�Ƿ�����м�ĵ� 
			for (int j = ps; j <= rlim; j++) //�м�ĵ���ܸ����Ҳ���ܸ��ұ� 
				{a[j] = -3; ck = 1;}
			
			/*cout<<i<<":\n";
			for (int j = 0; j <n; j++)
				cout<<a[j]<<" ";
			puts("");*/
			
			/*if (i == 0) //ȫ�Ǵ��ұ�ƥ�����Ҫ���� 
			{
				int u = 0;
				while (a[u] > 0 && u <= n - 1) ++u; //��һ��Ҫɾ��λ��
				ans = min(ans, n - u);
				cout<<"te:"<<n - u<<endl;
				continue;
			}*/
			
			int st;
			for (int j = 0; j < n; j++) //�ҵ����һ��ƥ���λ�� 
				if (a[j] == m) {st = j; break;}
			if (i == 0) st = -1;
			//�м�ĵ���ұ�
			tot = 0; 
			int u = st;
			while (u >= 0 && a[u] != -2) --u; //���һ��-2��λ�� 
			if (u >= 0) ++tot; //�������ȫƥ�䣬��Ҫhome��+1�� 
			while (u >= 0) //ͳ����ߵĴ��� 
			{
				if (a[u] == -2) tot += 2;
				else ++tot;
				--u;
			}
			u = st + 1;
			while (u <= n - 1 && a[u] > 0) ++u; //�ұߵ�һ����Ҫɾ��λ��
			ans = min(ans, tot + n - u);
			//cout<<"you: "<< tot + n - u<<endl;
			
			//�м�ĵ����ߣ�����������м�ĵ㣬�������м�ĵ���ұ߾��Ǵ� 
			if (ck) 
			{
				tot = 1; //home��һ�� 
				for (int j = 0; j <= st; j++)
					if (a[j] == -2) tot += 2;
					else ++tot;
				u = st + 1;
				while (a[u] == -3 && u <= n - 1) {tot += 2; ++u;}
				while (a[u] > 0 && u <= n - 1) ++u; //��һ����Ҫɾ��λ��
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
