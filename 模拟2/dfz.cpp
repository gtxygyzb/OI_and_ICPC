#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+5;
const int maxm=1e6+5;
int a[maxn];
vector<int>v[maxn];
int siz[maxn],son[maxn],Son;
int cnt[maxn*15][21][2];
int base[25];
ll sum;
void dfs(int x,int fa)//记录重儿子
{
	siz[x]=1;
	for(auto to:v[x])
	{
		if(to==fa)continue;
		dfs(to,x);
		siz[x]+=siz[to];
		if(siz[to]>siz[son[x]])
		{
			son[x] = to;
		}
	}
}
void update(int x,int fa,int num)
{
//	printf("cal = %d\n",x);
	int val = a[x] ^ num;
	for (int i = 0; i <= 20; ++i)
	{
		sum += 1ll * base[i] * cnt[val][i][!((x >> i) & 1)];
//		if(cnt[val][i][!((x >> i) & 1)] > 0)
//			printf("summmmmmmmmmmmm = %lld\n",sum);
	}
	for (auto to:v[x])
	{
		if (to == fa || to == Son)
			continue;
		update(to, x,num);
	}
}
void add(int x,int fa,int val)
{
//	if(val==1)
//		printf("add2 = %d\n",x);
//	else	printf("del = %d\n",x);
	for(int i=0; i<=20; i++)
	{
		cnt[a[x]][i][(x>>i)&1]+=val;
	}
	for (auto to:v[x])
	{
		if (to == fa || to == Son)
			continue;
		add(to, x, val);
	}
}
void dfs2(int x,int fa,int keep)
{
//	printf("x = %d\n",x);
	for(auto to:v[x])
	{
		if(to==fa||to==son[x])continue;
		dfs2(to,x,0);
	}
	if(son[x])
	{
		dfs2(son[x],x,1);
		Son = son[x];
	}
	//暴力统计x及其所有轻儿子的贡献合并到刚算出的重儿子信息里
	for(auto to:v[x])
	{
		if(to==fa||to==son[x])continue;
		update(to,x,a[x]);
		add(to,x,1);
	}
//	printf("add1 = %d\n",x);
	for (int i = 0; i <= 20; ++i)
	{
		cnt[a[x]][i][(x >> i) & 1]++;
	}
	Son = 0;
	if(!keep)
	{
//		printf("xxxx = %d\n",x);
		add(x, fa, -1);
	}
}
int main()
{
	base[0]=1;
	for (int i = 1; i <= 20; ++i)
	{
		base[i] = base[i - 1] * 2;
	}
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<n; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);//记录重儿子
	dfs2(1,0,0);
	printf("%lld\n",sum);
	return 0;
}
/*
6
4 2 1 6 6 5
1 2
2 3
1 4
4 5
4 6

*/
