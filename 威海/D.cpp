#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
typedef pair<int,int> P;
int a[19];
vector<P> p[19];
int dp[MAXN];
char s[100];

int main()
{
	p[1].push_back(P(0,2));
	p[3].push_back(P(0,7));
	p[4].push_back(P(0,9));
	p[4].push_back(P(1,8));
	p[4].push_back(P(3,5));
	p[5].push_back(P(1,10));
	p[5].push_back(P(9,2));
	p[5].push_back(P(4,6));
	p[6].push_back(P(11,2));
	p[8].push_back(P(7,9));
	p[8].push_back(P(3,13));
	p[8].push_back(P(4,12));
	p[9].push_back(P(4,14));
	p[9].push_back(P(5,13));
	p[9].push_back(P(8,10));
	p[10].push_back(P(5,15));
	p[10].push_back(P(6,14));
	p[10].push_back(P(9,11));
	p[12].push_back(P(16,7));
	p[13].push_back(P(8,17));
	p[13].push_back(P(9,16));
	p[13].push_back(P(12,14));
	p[14].push_back(P(9,18));
	p[14].push_back(P(10,17));
	p[14].push_back(P(13,15));
	p[15].push_back(P(11,18));
	p[17].push_back(P(16,18));

	for(int i=0;i<19;i++)
	{
		scanf("%d",a+i);
	}
	for(int k=1;k<=19;k++)
	{
		
	for(int i=0;i<(1<<19);i++)
	{
		int cnt=0;
		for(int j=0;j<19;j++)
		{
			if(i&(1<<j)) cnt++;
		}
		if(cnt!=k) continue;
		for(int j=0;j<19;j++)
		{
			if(i&(1<<j)) 
			{
				dp[i]=max(dp[i],dp[i^(1<<j)]);
				for(auto& tp:p[j])
				{
					if(i&(1<<tp.first)&&(!(i&(1<<tp.second)))) dp[i]=max(dp[i],a[j]+dp[i^(1<<j)^(1<<tp.first)^(1<<tp.second)]);
					if(i&(1<<tp.second)&&(!(i&(1<<tp.first)))) dp[i]=max(dp[i],a[j]+dp[i^(1<<j)^(1<<tp.first)^(1<<tp.second)]);
				}
			}
		}
	}
}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		scanf("%s",s+4);
		scanf("%s",s+8);
		scanf("%s",s+13);
		scanf("%s",s+17);
		int S=0;
		for(int i=0;i<19;i++)
		{
			if(s[i+1]=='#') S+=(1<<i);
		}
		printf("%d\n",dp[S]);
	}
	return 0;
}

