#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const int MAXN=1e6+10;

ll a[MAXN],b[MAXN],sum[MAXN];
P p[MAXN];
int nxt[MAXN];
int c[MAXN];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ans+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",b+i);
		p[i].first=b[i]-a[i];
		p[i].second=i;
	}
	sort(p+1,p+n+1);
	sum[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		sum[i]=sum[i+1]+p[i].first;
	}
	for(int i=1;i<=n;i++)
	{
		nxt[p[i].second]=i;
	}
	
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int m;
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",c+i);
			c[i]=nxt[c[i]];
		}
		sort(c+1,c+m+1);
		c[0]=0;
		int tp=k;
		ll res=ans;
		for(int i=m;i>=0;i--)
		{
			if(n-c[i]>=tp)
			{
				for(int j=i+1;j<=m;j++) 
				{
					res-=p[c[j]].first;
				}
				res+=sum[n-tp+1];
				break;
			}
			else
			{
				tp++;
			}
		}
		printf("%lld\n",res);
	}
	
	return 0;
} 
