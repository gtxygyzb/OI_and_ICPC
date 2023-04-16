#include <bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=1e6+50; 

int inv2,fac[N]={1},f[N];
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
	for (int i=1;i<=n;i++)
		fac[i]=1LL*fac[i-1]*i%P;
	inv2=power(2,P-2);
	f[2]=1;
	
	for (int i=3;i<=n;i++)
		f[i]=(1LL*fac[i-1]*i%P*(i-1)%P*inv2%P+1LL*i*f[i-1]%P)%P;
		
	printf("%d\n",1LL*f[n]*power(fac[n],P-2)%P);
	return 0;
}

