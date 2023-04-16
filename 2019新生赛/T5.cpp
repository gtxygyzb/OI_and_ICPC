#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int P=1e9+7;
ll n;
int q;

int power(int a,ll k)
{
	int ret=1;
	for (;k;k>>=1,a=1LL*a*a%P)
		if (k&1) ret=1LL*ret*a%P;
	return ret;
}
int calc(ll k)
{
	if (k==1) return q;
	ll mid=k>>1;
	
	int hh=calc(mid);
	if (k&1) return ( 1LL*power(10,mid)* ((1LL*hh*10%P+q) %P) %P+hh)%P;
	return(1LL*power(10,mid)*hh%P+hh)%P;
}

int main()
{
	cin>>n>>q;
	cout<<calc(n);
	return 0;
}

