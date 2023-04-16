#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+10;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll n,m;
		scanf("%lld%lld",&n,&m);
		ll tp1=n*(n+1)/2,tp2=m*(m+1)/2;
		if(tp1*tp2%2==1) puts("No");
		else
		{
			puts("Yes");
			if(tp1%2==0)
			{
				ll nd=n*(n+1)/4;
				vector<int> v;
				ll all=n;
				while(nd)
				{
					/*if(nd==1) 
					{
						v.push_back(1);
						nd--;
						continue;
					}*/
					ll tp=(sqrt(1+8*nd)-1)/2;
					while(tp*(tp+1)/2<=nd) tp++;
					while(tp*(tp+1)/2>nd) tp--;
					while((nd-tp*(tp+1)/2)<all-tp) tp--;
					v.push_back(tp);
					all-=tp;
					nd-=tp*(tp+1)/2;
				}
				
				int now=0;
				for(int cnt:v)
				{
					for(int i=1;i<=cnt;i++)
					{
						for(int j=1;j<=m;j++)
						{
							printf("%d%c",now," \n"[j==m]);
						}
						//puts("");
					}
					now^=1;
				}
			}
			else
			{
				ll nd=m*(m+1)/4;
				vector<int> v;
				ll all=m;
				while(nd)
				{
					/*if(nd==1) 
					{
						v.push_back(1);
						nd--;
						continue;
					}*/
					ll tp=(sqrt(1+8*nd)-1)/2;
					while(tp*(tp+1)/2<=nd) tp++;
					while(tp*(tp+1)/2>nd) tp--;
					while((nd-tp*(tp+1)/2)<all-tp) tp--;
					all-=tp;
					v.push_back(tp);
					//printf("wqeq %lld\n",tp);
					nd-=tp*(tp+1)/2;
				}
				//printf("%d\n",v.size());
				//for(int x:v) printf("%d ",x);
				int now=0;
				for(int i=1;i<=n;i++)
				{
					now=0;
					int tp=0;
					for(int cnt:v)
					{
						for(int j=1;j<=cnt;j++)
						{
							tp++;
							printf("%d%c",now," \n"[tp==m]);
						}
						now^=1;
					}
					//puts("");
				}
			}
		}
	}
	return 0;
}

