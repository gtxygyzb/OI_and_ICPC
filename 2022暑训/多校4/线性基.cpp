#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=61;
int n;
ll a[N],bin[N]={1};
void add(ll val)
{
	for (int i=59;i>=0;i--)
		if (val&bin[i])
		{
			if (!a[i]) {a[i]=val; break;}
			else val^=a[i];
		}
}
ll query()
{
	ll ret=0;
	for (int i=59;i>=0;i--)
		if ((ret^a[i])>ret) ret^=a[i];
	return ret;
}
int main()
{
	for (int i=1;i<=59;i++)
		bin[i]=bin[i-1]<<1;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 0; i <= 59; i++)
			a[i] = 0;
		for (ll x;n--;)
		{
			scanf("%lld",&x);
			add(x);
		}
		printf("%lld\n",query());
	}
	return 0;
}
