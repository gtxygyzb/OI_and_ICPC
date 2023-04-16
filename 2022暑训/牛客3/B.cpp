#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+50,M=2e6+50;
const ll inf=0x3f3f3f3f3f3f3f3f;

int S,T,etop=1,head[N];
int pre[N],vis[N],tim;

ll dis[N];

struct Edge
{
	int u,v,r,c,nxt;
}e[M*2]; //双倍边 
void addedge(int u,int v,int r,int c)
{
	e[++etop]={u,v,r,c,head[u]};
	head[u]=etop;
}
void add(int u,int v,int r,int c)
{
	addedge(u,v,r,c);
	addedge(v,u,0,-c);
}
int spfa() //找费用最小的一条路 并用pre记录路径 
{
	queue <int> q;
	q.push(S);
	memset(pre,0,sizeof(pre));
	memset(dis,0x3f,sizeof(dis));
    //cout<<dis[S]<<" "<<inf<<endl;
	dis[S]=0; vis[S]=++tim;
	while (!q.empty())
	{
		int u=q.front(); q.pop();
		for (int v,i=head[u];i;i=e[i].nxt)
		{
			v=e[i].v;
			if (e[i].r&&dis[v]>dis[u]+e[i].c)
			{
				dis[v]=dis[u]+e[i].c;
				pre[v]=i;
				if (vis[v]!=tim)
				{
					vis[v]=tim;
					q.push(v);
				}
			}
		}
		vis[u]=0;
	}
	return dis[T]!=inf;
}
void mcmf()
{
	int flow=0;
    ll cost = 0;
	while (spfa())
	{
		int minflow=1e9;
		for (int i=pre[T];i;i=pre[e[i].u])
			minflow=min(minflow,e[i].r);
		for (int i=pre[T];i;i=pre[e[i].u])
		{
			e[i].r-=minflow;
			e[i^1].r+=minflow;
		} 
		flow+=minflow;
		cost+=dis[T]*minflow;
	}
	printf("%lld\n", cost);
}
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    S =  n + k + 1; T = n + k + 2;
    for (int r, i = 1; i <= k; i++)
    {
        scanf("%d", &r);
        add(n + i, T, r, 0);
    }
    for (int w, i = 1; i <= n; i++)
    {
        add(S, i, 1, 0);
        for (int j = 1; j <= k; j++)
        {
            scanf("%d", &w);
            add(i, n + j, 1, w);
        }
    }
    mcmf();
    return 0;
}
