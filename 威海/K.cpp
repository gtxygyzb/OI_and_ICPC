#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;

P getans(int x,int k)
{
	if(1ll*k*(k+1)/2>x) return P(-1,-1);
	int del=x-k*(k+1)/2;
	int lb=1+del/k;
	int rb=lb+k-1;
	if(del%k!=0) rb++;
	return P(lb,rb);
}

void solve()
{
	int n;
	scanf("%d",&n);
	int lrb=INF,rlb=1;
	vector<P> res;
	for(int i=1;i<=n;i++)
	{
		int t,k,x;
		scanf("%d%d%d",&t,&k,&x);
		if(t==1)
		{
			P p=getans(x,k);
			if(p.first==-1) 
			{
				puts("0");
				return;
			}
			lrb=min(lrb,p.first);
			rlb=max(rlb,p.second);
		}
		else
		{
			P p=getans(x,k);
			if(p.first!=-1) res.push_back(p);
		}
	}
	if(lrb>rlb) puts("-1");
	else
	{
		int llb=1,rrb=INF;
		map<int,int> rbb;
		for(P& p:res)
		{
			//printf("abc %d %d\n",p.first,p.second);
			//printf("abc %d %d\n",p.first,p.second);
			if(p.first>=lrb&&p.second<=rlb) 
			{
				puts("0");
				return;
			}
			if(p.first<lrb&&p.second>rlb)
			{
				if(rbb[p.first]) rbb[p.first]=p.second;
				else rbb[p.first]=max(rbb[p.first],p.second);
			}
			else if(p.first>=lrb)
			{
				rrb=min(rrb,p.second-1);
			}
			else
			{
				llb=max(llb,p.first+1);
			}
		}
		
		vector<P> tpp;
		int rtp=0;
		for(auto& p:rbb)
		{
			if(p.first<llb) continue;
			if(p.second<=rtp) continue;
			tpp.push_back(p);
			rtp=p.second;
		}
		
		ll ans=0;
		if(tpp.empty())
		{
			int lbb=lrb-llb+1;
			//printf("qwe %d %d %d %d\n",llb,lrb,rlb,rrb);
			if(rrb==INF) puts("-1");
			else
			{
				printf("%lld\n",1ll*lbb*(rrb-rlb+1));
			}
		}
		else
		{
			int lbb=llb;
			for(int i=0;i<tpp.size();i++)
			{
				P p=tpp[i];
				ans+=1ll*(p.first-lbb)*max(0ll,(min(p.second-1,rrb)-rlb+1ll));
				lbb=p.first;
			}
			ans+=1ll*max((lrb-lbb+1),0)*max(0ll,rrb-rlb+1ll);
			if(rrb==INF) puts("-1");
			else printf("%lld\n",ans);
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}

