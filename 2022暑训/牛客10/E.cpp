// luogu-judger-enable-o2
#include<bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 5e3+50;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> P;
struct edge{int from, to, cap, cost, rev, next;};
int n;                          //顶点数
int tot;                        //统计边数
edge G[MAXN*20];                //图的邻接表表示
int head[MAXN];                 //每个顶点的第一条边
int h[MAXN];                    //顶点的势
int dist[MAXN];                 //最短距离
int prevv[MAXN], preve[MAXN];   //最短路中的前驱结点和对应的边
 
//优化输入
template <class T>
inline bool scan_d(T &ret) {
	char c; int sgn;
	if (c = getchar(), c == EOF) return 0;
	while (c != '-' && (c<'0' || c>'9')) c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
	ret *= sgn;
	return 1;
}
 
//图初始化
void init()
{
    memset(head, -1, sizeof(head));
    tot = 2;
}
 
//向图中增加一条从from到to容量为cap费用为cost的边
void add(int from, int to, int cap, int cost){
    G[tot] = edge{from, to, cap, cost, tot+1, head[from]}; head[from] = tot++;
    G[tot] = edge{to, from, 0, -cost, tot-1, head[to]}; head[to] = tot++;
//    G[from].push_back((edge){to, cap, cost, G[to].size()});
//    G[to].push_back((edge){from, 0, -cost, G[from].size()-1});
}
 
//求解从s到t流量为f的最小费用流
//如果没有流量为f的流，则返回-1
//当f为0时，是流量为f的最小费用
//当f大于0时，是最大流的最小费用
int min_cost_flow(int s, int t, int &f){
    int res = 0;
    fill(h, h+n+1,0); //初始化h
    while(f>0){
        //使用Dijstra算法更新h
        priority_queue<P, vector<P>, greater<P> >que;
        fill(dist, dist+n+1, INF);
        dist[s] = 0;
        que.push(P(0, s));
        while(!que.empty()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(dist[v]<p.first) continue;
            for(int i = head[p.second]; ~i; i = G[i].next){
                edge &e = G[i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    //prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
        if(dist[t] == INF){
            return res;
        }
        for(int v = 1; v <= n; v++) h[v] += dist[v];
 
        int d = f;
        for(int v = t; v != s; v = G[preve[v]].from){
            d = min(d, G[preve[v]].cap);
        }
        f -= d;
        res += d*h[t];
        for(int v = t; v != s; v = G[preve[v]].from){
            edge &e = G[preve[v]];
            e.cap -= d;
            G[e.rev].cap += d;
        }
    }
    return f;
}
 
int main() {
	//ios::sync_with_stdio(false);
	init();
	int n, m;
	char ch[1050];
	scanf("%d%d", &n, &m);
    s = n + m + 1; t = n + m + 2;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", ch);
        for (int j = 0; j < m; j++)
            if (ch[j] == '1') add(i, n + j + 1, 1, 0);
    }
 
    int et = tot;
 
    for (int i = 1; i <= n; i++)
        add(S, i, 1, 0);
    for (int j = n + 1; j <= n + m; j++)
        for (int k = 1; k <= n; k++)
            add(j, T, 1, k);
 
    int ret = min_cost_flow();
    if (ret != n) puts("-1");
    else
    {
        for (int i = 2; i <= et; i += 2)
            if (e[i].r == 0) printf("%d ", e[i].v - n);
        puts("");
    }
	
    int maxflow = INF;
    int mincost = min_cost_flow(s, t, maxflow);
    printf("%d %d\n", INF-maxflow, mincost);
	return 0;
}
/*
9 2
5 3 2 1 4 2 1 4 6
*/