#include <bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int power(int x,int k)
{
	int ret=1;
	for (;k;x=1LL*x*x%P,k>>=1)
		if (k&1) ret=1LL*ret*x%P;
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",(1+1+1LL*(n-1)*power(2,P-2)%P)%P);
	return 0;
}

