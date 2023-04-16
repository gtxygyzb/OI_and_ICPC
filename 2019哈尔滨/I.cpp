#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int MAXN=1e5+10;
int a[MAXN];
typedef long long ll;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		bool f=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<i-1||a[i]>n-1) f=0;
			if(i>1&&a[i]<a[i-1]) f=0;
		}
		if(a[1]!=0) f=0;
		if(!f) puts("0");
		else
		{
			ll ans=1;
			ll lef=0;
			for(int i=2;i<=n;i++)
			{
				if(a[i]==a[i-1])
				{
					ans=ans*lef%mod;
					lef--;
				}
				else
				{
					ans=ans*2%mod;
					lef+=a[i]-a[i-1]-1;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

