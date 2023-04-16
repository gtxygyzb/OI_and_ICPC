#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
//#define int long long
//#define double long double
#define re register int
#define void inline void
#define eps 1e-18
//#define mod 1e9+7
#define ls(p) p<<1
#define rs(p) p<<1|1
#define pb push_back
#define P pair < int , int >
#define mk make_pair
#define fi first
#define se second
#define x0 xx
#define y0 yy
using namespace std;
const int N=5e5+1;//?????????? 4e8.
int n, s,t;
namespace HLPP
{
	struct node
	{
		int ver,edge,next;
	}e[N];
    
	int tot=1,head[N];
	int gap[N],ee[N],h[N],inq[N];
    void init()
    {
        tot = 1;
        for (int i = 0; i <= n + n; i++) ee[i] = inq[i] = gap[i] = h[i] = head[i] = 0;
    }
	struct cmp
	{
		bool operator()(int a,int b)  const
		{
			return h[a]<h[b];
		}
	};
	priority_queue < int , vector < int > , cmp > pq;
	void add(int x,int y,int z)
	{
		e[++tot].ver=y;
		e[tot].edge=z;
		e[tot].next=head[x];
		head[x]=tot;
	}
	void addedge(int x,int y,int z)
	{
        cout<<"add: "<<x<<" "<<y<<" "<<z<<endl;
		add(x,y,z);add(y,x,0);
	}
	bool bfs()
	{
		queue < int > q;
		for(re i=0;i<=n;i++)  h[i]=1e9;
		h[t]=0,q.push(t);
		while(q.size())
		{
			int x=q.front();q.pop();
			for(re i=head[x];i;i=e[i].next)
			{
				int y=e[i].ver;
				if(e[i^1].edge&&h[y]>h[x]+1)  h[y]=h[x]+1,q.push(y);
			}
		}
		return h[s]!=1e9;
	}
	void push(int x)
	{
		int d;
		for(re i=head[x];i;i=e[i].next)
		{
			int y=e[i].ver;
			int z=e[i].edge;
			if(z&&h[y]+1==h[x])
			{
				d=min(ee[x],z);
				e[i].edge-=d;e[i^1].edge+=d;
				ee[x]-=d;ee[y]+=d;
				if(y!=s&&y!=t&&!inq[y])  pq.push(y),inq[y]=1;
				if(!ee[x])  break;
			}
		}
	}
	void relabel(int x)
	{
		h[x]=1e9;
		for(re i=head[x];i;i=e[i].next)
		{
			int y=e[i].ver;
			int z=e[i].edge;
			if(z&&h[y]+1<h[x])  h[x]=h[y]+1;
		}
	}
	int hlpp()
	{
		if(!bfs())  return 0;
		h[s]=n;
		for(re i=0;i<=n*2;i++)  gap[i]=0;
		for(re i=1;i<=n;i++)  if(h[i]<1e9)  ++gap[h[i]];
		for(re i=head[s];i;i=e[i].next)
		{
			int y=e[i].ver;
			int z=e[i].edge;
			int d=z;
			e[i].edge-=d;
			e[i^1].edge+=d;
			ee[s]-=d,ee[y]+=d;
			if(y!=s&&y!=t&&!inq[y])   pq.push(y),inq[y]=1;
		}
		while(pq.size())
		{
			int x=pq.top();pq.pop();push(x);inq[x]=0;
            cout<<"x: "<<x<<" "<<ee[x]<<endl;
			if(ee[x])
			{
                cout<<"hx:"<<h[x]<<endl;
				if(!--gap[h[x]])
                {
                    for(re i=1;i<=n;i++)  if(i!=s&&i!=t&&h[i]>h[x]&&h[i]<n+1)  h[i]=n+1;
                }
				relabel(x);++gap[h[x]];
				pq.push(x);inq[x]=1;
			}
		}
		return ee[t];
	}
}

const int NN = 1e3 + 50;
int n1, m1, m2;
int sheng[NN];
int wei[NN][NN], id[NN][NN];

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
    int flag = 1, tr = 1;
    HLPP::init();
    for (int i = 2; i <= n1; i++)
        for (int j = i + 1 ; j <= n1; j++)
            if (wei[i][j]) id[i][j] = ++tr;
    s = 1; t = tr + n1;
    //cout<<"S: "<<s<<" T:"<< t<<" tr: "<<tr<<" n1:" <<n1<<endl; 

    int flag2 = 0;
    for (int i = 2; i <= n1; i++)
        for (int j = i + 1 ; j <= n1; j++)
            if (wei[i][j])
            {
                HLPP::addedge(s, id[i][j], wei[i][j]);
                HLPP::addedge(id[i][j], tr + i - 1, inf);
                HLPP::addedge(id[i][j], tr + j - 1, inf);
                flag2 = 1;
            }
    n = tr + n1; 
    for (int i = 2; i <= n1 && flag; i++)
    {
        if (sheng[i] > sl1) flag = 0;
        else HLPP::addedge(tr + i - 1, t, sl1 - sheng[i]);
    }
    cout<<"n:"<<n<<endl;
    if (flag2 == 0 && flag == 1) {puts("YES"); return ;}
    if (!flag) {puts("NO"); return ;}
	puts(HLPP::hlpp() == m2 ? "YES" : "NO");
    
}
signed main()
{
    int T;
    scanf("%d", &T);
    for(int index=1;index<=T;index++)
    {
//        printf("Case #%lld: ",index);
        solve();
//        puts("");
    }
    return 0;
}
/*
5

3 1 3
1 2 1
2 3
2 3
2 3

3 1 2
1 2 1
2 3
2 3

3 1 3
1 2 1
2 3
2 3
2 3

4 2 1
2 3 1
3 2 1
1 4
4 2 2
2 3 1
2 4 1
1 2
3 4

1
1000 1 1
1 2 0
2 3
*/
