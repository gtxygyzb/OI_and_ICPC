#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int n;
int power(int a,int k)
{
	int ret=1;
	for (;k;k>>=1,a=1LL*a*a%P)
		if (k&1) ret=1LL*ret*a%P;
	return ret;
}
int main()
{
	scanf("%d", &n);
	n -= 2;
	if (n <= 0) return 0*puts("0");
	int ans = power(2, n);
	if (!(n&1))
	{
		int del = 1;
		for (int i=n;i>(n>>1);i--)
			del = 1LL*del*i%P;
		for (int i=(n>>1);i>1;i--)
			del = 1LL*del*power(i,P-2)%P;
		ans = ((ans - del)%P + P) % P;
	}
	printf("%d\n", ans);
	return 0;
}

