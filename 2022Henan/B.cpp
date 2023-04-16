#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50, P = 998244353;
int n;
char s[N];
ll g(char c)
{
	if (c == 'a') return 1;
	if (c == 'e') return 2;
	if (c == 'h') return 3;
	return 4;
}
ll f[N];
int main()
{
	scanf("%s", s);
	n = strlen(s);
	ll ans = 0;
	for (int i = 0; i < min(n, 14); i++)
	{
		f[0] = g(s[i]);
		for (int j = 1; j < n; j++)
		{
			f[j] = 0; 
			ll base = 1, h = g(s[(i + j) % n]);
			int k;
			for (k = j - 1; k >= max(0, j - 14); k--)
			{
				f[j] = max(f[j], f[k] + h);
				base *= 31;
				h += base * g(s[(i + k)% n]);
				h %= P;
			}
			if (k == -1) f[j] = max(f[j], h);
			//cout<<i<<" "<<j<<" "<<f[j]<<endl;
		}
		//cout<<f[n - 1]<<endl;
		ans = max(ans, f[n - 1]);
	}
	printf("%lld\n", ans);
	return 0;
}
/*
hheehnahnhnehaaeneneanheannheahehhneeaahhhhhnaanhennheanhaneeehhaneennahaaaahehnanhhaeehahaeahhehhhn
*/
