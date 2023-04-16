#include <bits/stdc++.h>
using namespace std;
const int N=1e4+50,M=1e5+50,inf=0x3f3f3f3f;
int S,T,head[N],etop=1,tim,dis[N],vis[N];

struct Edge
{
	int v,r,nxt;
}e[M<<1];
void addedge(int u,int v,int r)
{
	e[++etop].v=v;
	e[etop].r=r;
	e[etop].nxt=head[u];
	head[u]=etop;
}
void add(int u,int v,int r)
{
	addedge(u,v,r);
	addedge(v,u,0);
}

int bfs()
{
	++tim;
	dis[S]=0; vis[S]=tim;
	queue <int> q;
	q.push(S);
	while (!q.empty())
	{
		int u=q.front(); q.pop();
		for (int v,i=head[u];i;i=e[i].nxt)
		{
			v=e[i].v;
			if (vis[v]!=tim&&e[i].r)
			{
				vis[v]=tim;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
		if (vis[T]==tim) break;
	}
	return vis[T]==tim;
}
int dfs(int u,int cur)
{
	if (u==T) return cur;
	if (dis[u]>=dis[T]) return 0;
	for (int i=head[u];i&&cur;i=e[i].nxt)
	{
		int v=e[i].v,flow;
		if (e[i].r&&dis[v]==dis[u]+1&& (flow=dfs(v,min(cur,e[i].r))))
		{
			e[i].r-=flow;
			e[i^1].r+=flow;
			return flow;
		}
	}
	dis[u]=-1;
	return 0;
}
int dinic()
{
	int ret=0,flow;
	while (bfs())
		while (flow=dfs(S,inf))
			ret+=flow;
	return ret;
}

const int NN = 1e3 + 50;
int n1, m1, m2;
int sheng[NN];
int wei[NN][NN], id[NN][NN];

void init()
{
    etop = 1;
    memset(head, 0, sizeof(head));
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    tim = 0;
}
void solve()
{
    scanf("%d%d%d", &n1, &m1, &m2);

    for (int i = 1; i <= n1; i++) sheng[i] = 0;
    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n1; j++)
            wei[i][j] = 0;

    for (int x, y, z, i = 1; i <= m1; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        if (z == 1) ++sheng[x];
        else ++sheng[y];
    }
    int sl1 = sheng[1];
    for (int x, y, i = 1; i <= m2; i++)
    {
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        ++wei[x][y];
        if (x == 1) ++sl1;
    }
    int flag = 1, tr = 1, cnt2 = 0;
    init();
    for (int i = 2; i <= n1; i++)
        for (int j = i + 1 ; j <= n1; j++)
            if (wei[i][j]) id[i][j] = ++tr, cnt2 += wei[i][j];
    S = 1; T = tr + n1;
    //cout<<"S: "<<s<<" T:"<< t<<" tr: "<<tr<<" n1:" <<n1<<endl; 

    int flag2 = 0;
    for (int i = 2; i <= n1; i++)
        for (int j = i + 1 ; j <= n1; j++)
            if (wei[i][j])
            {
                add(S, id[i][j], wei[i][j]);
                add(id[i][j], tr + i - 1, inf);
                add(id[i][j], tr + j - 1, inf);
                flag2 = 1;
            }
    for (int i = 2; i <= n1 && flag; i++)
    {
        if (sheng[i] > sl1) flag = 0;
        else add(tr + i - 1, T, sl1 - sheng[i]);
    }
    //cout<<"n:"<<n<<endl;
    if (flag2 == 0 && flag == 1) {puts("YES"); return ;}
    if (!flag) {puts("NO"); return ;}
	puts(dinic() == cnt2 ? "YES" : "NO");
    
}

int main()
{
    int TT;
    scanf("%d", &TT);
    for(int index=1;index<=TT;index++)
    {
//        printf("Case #%lld: ",index);
        solve();
//        puts("");
    }
    return 0;
}