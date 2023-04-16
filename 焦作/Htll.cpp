#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e6 + 50;

int n, a[N];
int mxx[N][21];
int lg2[N];
int fa[N], mx[N], pos[N], last, top;
int t[N], rk[N];
map <int, int> ch[N];
ll dp[N];
vector<int> poss[N];

int findmx(int l,int r)
{
	int len=r-l+1;
	int j=lg2[len];
	return max(mxx[l][j],mxx[r-(1<<j)+1][j]);
}

ll query(int len,int rb)
{
    if (len == 0) return 0;
	int lb=rb-len+1;
	int mx=findmx(lb,rb);
	int mxpos=*lower_bound(poss[mx].begin(),poss[mx].end(),lb);
    //cout<<"query:"<<dp[rb]-dp[mxpos]+(mxpos-lb+1)*1ll*a[mxpos]<<endl;
	return dp[rb]-dp[mxpos]+(mxpos-lb+1)*1ll*a[mxpos];
}

unsigned long long ans;
void add(int c, int id)
{
    int p = last, np = last = ++top;
    mx[np] = mx[p] + 1;
    pos[np] = id;
    for (; !ch[p][c] && p; p = fa[p]) ch[p][c] = np;
    if (!p) fa[np] = 1;
    else
    {
        int q = ch[p][c];
        if (mx[q] == mx[p] + 1) fa[np] = q;
        else
        {
            int nq = ++top;
            fa[nq] = fa[q];
            mx[nq] = mx[p] + 1;
            fa[q] = fa[np] = nq;
            ch[nq] = ch[q];
            for (; ch[p][c] == q; p = fa[p])
                ch[p][c] = nq;
        }
    }
}
void merge()
{
    for (int i = 1; i <= top; i++) ++t[mx[i]];
    for (int i = 1; i <= top; i++) t[i] += t[i - 1];
    for (int i = top; i >= 1; i--) rk[t[mx[i]]--] = i;
    for (int i = top; i >= 2; i--)
    {
        int u = rk[i];
        pos[fa[u]] = max(pos[fa[u]], pos[u]);
    }
    for (int i = top; i >= 2; i--)
    {
        int u = rk[i];
        ans -= query(mx[fa[u]], pos[u]);
        ans += query(mx[u], pos[u]);
    }
}

void init()
{
    last = top = 1; ans = 0;
    for (int i = 1; i <= n + n; i++)
    {
        ch[i].clear();
        pos[i] = rk[i] = t[i] = fa[i] = mx[i] = 0;
    }
}
int que[N],nxt[N];
int main()
{
	lg2[1]=0;
	for(int i=2;i<N;i++)
	{
		lg2[i]=lg2[i>>1]+1;
	}
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            poss[a[i]].push_back(i);
            mxx[i][0]=a[i];
            add(a[i], i);
        }
        int lb=1,rb=0;
        for(int i=1;i<=n;i++) nxt[i]=-1;
        for(int i=n;i>=1;i--)
        {
        	while(rb>=lb&&a[que[rb]]<a[i])
        	{
        		nxt[que[rb]]=i;
        		rb--;
			}
			que[++rb]=i;
		}
		dp[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			if(nxt[i]==-1) dp[i]=1ll*i*a[i];
			else
			{
				dp[i]=1ll*a[i]*(i-nxt[i])+dp[nxt[i]];
			}
		}
        for(int j=1;j<=20;j++)
        {
        	for(int i=1;i+(1<<j)-1<=n;i++)
        	{
        		mxx[i][j]=max(mxx[i][j-1],mxx[i+(1<<(j-1))][j-1]);
			}
		}
        merge();
		
		for(int i=1;i<=n;i++) poss[a[i]].clear();
        cout<<ans<<endl;
    }
    return 0;
}
/*
1
5
9 2 9 8 4 
*/