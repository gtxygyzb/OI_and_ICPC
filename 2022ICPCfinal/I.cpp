#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		ll cnt0=0,cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			x--;
			if(x<0) cnt1++;
			else if(x>0) cnt2++;
			else cnt0++;
		}
		ll ans=cnt0*(cnt0-1)/2+cnt0*(cnt1+cnt2);
		ans+=cnt1*cnt2;
		printf("%lld\n",ans);
	}
	return 0;
}

