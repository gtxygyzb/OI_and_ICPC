#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

i128 getmx(i128 n)
{
	if(n<3) return 0;
	n-=3;
	i128 k=n/2;
//	if(k>n/2) k=n/2;
	i128 mx=-k*k+n*k+n+1;
//	k++;
//	if(k>n/2) k=n/2;
	//mx=max(-2*k*k+(n-1)*k+n+1,mx);
	return mx;
}

void pt(i128 n)
{
	vector<int> v;
	while(n)
	{
		v.push_back(n%10);
		n/=10;
	}
	if(v.empty()) v.push_back(0);
	reverse(v.begin(),v.end());
	for(int x:v) printf("%d",x);
	puts("");
}

int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	i128 mx=getmx(n);
	if(mx>=m)
	{
		pt(mx);
	}
	else
	{
		i128 lb=n,rb=m+30;
		while(rb-lb>1)
		{
			i128 mid=lb+rb>>1;
			if(getmx(mid)>=m) rb=mid;
			else lb=mid;
		}
		pt(rb);
	}
	
	
	return 0;
} 
