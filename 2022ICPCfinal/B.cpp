#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const ull seed = 131, P = 998244353;
const int N = 1e4 + 50;
char s[N];
ull ans;
int cnt[N], nxt[N], b[N];
ull sum[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		ans = 0;
		for (int pos = 2; pos <= n - 4; pos++)
		{
			ull s1 = 0, s2 = 0, bas = 1;
			ull t1 = 0, t2 = 0;
			for (int j = 0; j <= n; j++)
				nxt[j] = cnt[j] = sum[j] = 0;
				
			for (int j = 1; pos + j - 1 <= n && pos - j >= 1; j++)
			{
				s1 = s1 + bas * s[pos - j];
				t1 = (t1 + bas * s[pos - j]) % P;
				s2 = s2 * seed + s[pos + j - 1];
				t2 = (t2 * seed + s[pos + j - 1]) % P;
				if (s1 == s2 && t1 == t2) ++cnt[j];
				bas *= seed;
			}
			for (int j = 1; j <= n; j++)
				cnt[j] += cnt[j - 1];
			for (int i = pos; i <= n; i++)
				b[i - pos + 1] = s[i];
			int len = n - pos + 1;
			for (int j = 0, i = 2; i <= len; i++)
			{
				while (j && b[i] != b[j + 1]) j = nxt[j];
				if (b[i] == b[j + 1]) nxt[i] = ++j;
			}
			
			for (int i = len; i >= 1; i--)
				sum[i] = cnt[i - 1];
			for (int i = 1; i <= len; i++)
				sum[i] += sum[nxt[i]];
			
			
			for (int j = 0, i = 2; i <= len; i++)
			{
				while (j && b[i] != b[j + 1]) j = nxt[j];
				if (b[i] == b[j + 1]) ++j;
				while (j + j >= i) j = nxt[j];
				if (j > 1)
				{
					//cout<<pos<<" "<<i<<" "<<sum[j]<<endl;
					ans += sum[j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
101001010111101
*/
