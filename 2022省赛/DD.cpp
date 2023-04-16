#include <bits/stdc++.h> 
using namespace std;

const int N = 1e6 + 50;
const int P = 5999993;
typedef long long ll;


ll gethas(char *s,ll len)
{
	ll res=0;
	for(int i=0;i<len;i++)
	{
		res=(res*29+(s[i]-'a'+1))%P;
	}
	return res;
}
ll power(ll x, ll k)
{
	ll ret = 1;
	for (; k; k >>= 1, x = x * x % P)
		if (k&1) ret = ret * x % P;
	return ret;
}

bool check(ll x, ll len)
{
	for (int i = 1; i <= len; i++)
	{
		if (x % 29 == 0 || x % 29 > 26) return 0;
		x /= 29;
	}
	return x == 0;
}
void output(ll x, ll len)
{
	int t[100], top = 0;
	for (int i = 1; i <= len; i++)
	{
		t[++top] = x % 29;
		x /= 29;
	}
	for (int i = len; i >= 1; i--)
	{
		printf("%c", (char) (t[i] + 'a' - 1));
	}
	puts("");
}
char s[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		ll x = gethas(s, strlen(s)), y, len, pre;
		for (len = 4; len <= 50; len++)
		{
			pre = x * power(29, len) % P;
			y = ((x - pre) % P + P) % P;
			if (check(y, len)) break;
			//cout<<y<<endl;
			int flag = 0;
			for (int cs = 0; cs <= 10000; cs++)
			{
				y += 1ll * rand() * P;
				if (check(y, len)) {flag = 1; break;}
				y %= P;
			}
			if (flag) break;
		}
		printf("%s", s);
		output(y, len);
		//cout<<"qianhou:"<<pre<<" "<<y<<" "<<x<<endl;
	}
	return 0;
}
/*
2
c
n
*/
