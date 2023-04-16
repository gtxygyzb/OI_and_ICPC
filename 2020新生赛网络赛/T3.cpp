#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n,k;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		cin>>n>>k;
		if (k>=n) {cout<<n*(n-1)/2<<endl; continue;}
		ll num=n/k; //每组人数 
		ll r=n-num*k; //有几组多出来一个人
		ll ans1=(k-r)*num*n-num*num*(1+k-r)*(k-r)/2;
		ll m=n-num*(k-r);
		++num;
		ll ans2=(r-1)*num*m-num*num*(r-1)*r/2;
		cout<<ans1+ans2<<endl;
	}
	return 0;
}
/*
2
4 2
3 3
100
80000 9999999
*/
