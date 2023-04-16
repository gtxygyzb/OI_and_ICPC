#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+50;

int n,b[N],cnt[N],sum,p;
ll ans;

int main()
{
	scanf("%d%d",&n,&p);
	memset(cnt,-1,sizeof(cnt));
	cnt[0]=0;
	for (int a;n--;)
	{
		scanf("%d",&a);
		a%=p;
		sum=sum+a;
		if (sum>=p) sum-=p;
		++cnt[sum];
		ans+=cnt[sum];
	}
	cout<<ans<<endl;
	return 0;
}
/*
3 3
1 2 3

4 3
1 2 3 3

5 3
1 3 2 1 3
*/
