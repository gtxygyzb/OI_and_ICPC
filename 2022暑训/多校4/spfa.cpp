#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=1e6+10;

struct edge
{
	int to;
	ll cost,w;
	edge(int to,ll cost,ll w):to(to),cost(cost),w(w){}
};

struct Data
{
    int v;
    ll c,w;
    bool operator < (const Data& y) const
    {
        if(c==y.c) return w<y.w;
        else return c>y.c;
    }
    Data(int v,ll c,ll w):v(v),c(c),w(w){}
};

vector<edge> G[MAXN];
ll d[MAXN];
ll w[MAXN];
bool vis[MAXN];
int n, m;

int read()
{
    int x = 0; char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) ;
    for (; '0' <= ch && ch <= '9'; ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return x;
}

void dij(int s)
{
	priority_queue< Data > pq;

	fill(d, d + n + 1, INF);
	fill(w, w + n + 1, INF);
	//fill(vis, vis + n + 1, false);
	// fill(pre, pre + n + 1, -1);
	d[s] = 0;
	w[s]=0;
	pq.push(Data(s, 0,0));

	while (!pq.empty())
	{
		Data p = pq.top(); pq.pop();
		int v = p.v;

		if(d[v]!=p.c||w[v]!=p.w) continue;

		for (int i = 0; i < G[v].size(); i++)
		{
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost||(d[e.to] == d[v] + e.cost && w[e.to] > w[v] - e.w))
			{
				d[e.to] = d[v] + e.cost;
				w[e.to] = w[v] - e.w;
				if(d[e.to]<=d[n]&&e.to!=n&&w[e.to]>-1e15)
                    pq.push(Data(e.to,d[e.to], w[e.to]));
			}
		}
	}
}



int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        n = read(); m = read();
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            ll c,w;
            u = read(); v = read(); c = read(); w = read();
            //scanf("%d%d%lld%lld",&u,&v,&c,&w);
            G[u].push_back(edge(v,c,w));
        }
        dij(1);
        printf("%lld %lld\n",d[n],-w[n]);
    }

    return 0;
}
