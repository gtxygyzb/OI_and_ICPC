#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5010],b[5010];
int main()
{
	int n;
	scanf("%d",&n);
	ll d;
	scanf("%lld",&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	ll ans=-1e18;
	for(int i=1;i<=n;i++)
	{
		ll lb=a[i],rb=a[i]+d;
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j];
			if(a[j]<lb) b[j]=lb;
			if(a[j]>rb) b[j]=rb;
		}
		ll res=0;
		for(int i=1;i<n;i++)
		{
			res+=abs(b[i]-b[i+1]);
		}
		ans=max(ans,res);
		rb=a[i];
		lb=a[i]-d;
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j];
			if(a[j]<lb) b[j]=lb;
			if(a[j]>rb) b[j]=rb;
		}
		res=0;
		for(int i=1;i<n;i++)
		{
			res+=abs(b[i]-b[i+1]);
		}
		ans=max(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}

