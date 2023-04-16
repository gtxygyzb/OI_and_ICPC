#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
typedef pair<int,int> P;

int lb[MAXN],rb[MAXN],k[MAXN],sum[MAXN],id[MAXN],pre[MAXN];
vector<P> v[MAXN];
int n,m1,m2,m;

int lbt(int p) 
{
	return p&-p;
}

void add(int p,int x)
{
	while(p<=n)
	{
		sum[p]+=x;
		p+=lbt(p);
	}
}

int ask(int p)
{
	int ans=0;
	while(p)
	{
		ans+=sum[p];
		p-=lbt(p);
	}
	return ans;
}

int ask(int lb,int rb)
{
	return ask(rb)-ask(lb-1);
}

int getid(int i,int p)
{
	p=p-i+1;
	if(p<=0) p+=n;
	return p;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m1,&m2);
		m=0;
		for(int i=1;i<=m1;i++)
		{
			int l,r,kk;
			scanf("%d%d%d",&l,&r,&kk);
			if(kk==0) continue;
			m++;
			lb[m]=l,rb[m]=r,k[m]=kk;
		}
		m=m1;
		for(int i=1;i<=m2;i++)
		{
			int l,r,kk;
			scanf("%d%d%d",&l,&r,&kk);
			if(kk==0) continue;
			m++;
			lb[m]=r%n+1;rb[m]=l-1==0?n:l-1;
			k[m]=kk;
		}
		int ans=MAXN;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				v[j].clear();
				sum[j]=0;
				id[j] = j==1?i:(id[j-1]%n+1);
				pre[j]=j;
			}
			for(int j=1;j<=m;j++)
			{
				if(lb[j]<=rb[j]&&lb[j]<=i&&rb[j]>=i)
				{
					v[rb[j]].push_back(P(i,min(rb[j]-i+1,k[j])));
					if(k[j]>rb[j]-i+1) v[i-1==0?n:i-1].push_back(P(lb[j],k[j]-(rb[j]-i+1)));
				}
				else if(lb[j]>rb[j]&&(i>=lb[j]||i<=rb[j]))
				{
					if(i>=lb[j])
					{
						v[rb[j]].push_back(P(i,min(k[j],n-i+1+rb[j])));
						if(k[j]>n-i+1+rb[j]) v[i-1==0?n:i-1].push_back(P(lb[j],k[j]-(n-i+1+rb[j])));
					}
					else
					{
						v[rb[j]].push_back(P(i,min(rb[j]-i+1,k[j])));
						if(k[j]>rb[j]-i+1) v[i-1==0?n:i-1].push_back(P(lb[j],k[j]-(rb[j]-i+1)));
					}
				}
				else v[rb[j]].push_back(P(lb[j],k[j]));
			}

			for(int j=1;j<=n;j++)
			{
				int mx=0;
				for(P& p:v[id[j]])
				{
					//if(ask(getid(i,p.first),j)>=p.second) continue;
					mx=p.second-ask(getid(i,p.first),j);
					if(mx<=0) continue;
					while(mx)
				{
					add(pre[j],1);
					pre[j]=pre[pre[j]-1];
					mx--;
				}
				}

				
			}
			ans=min(ans,ask(n));
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}
 
