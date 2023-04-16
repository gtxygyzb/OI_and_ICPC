#include<set>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 300005
#define ENDL putchar('\n')
#define LL long long
#define DB double
#define lowbit(x) ((-x) & (x))
#define SI set<int>::iterator
LL read() {
	LL f = 1,x = 0;char s = getchar();
	while(s < '0' || s > '9') {if(s=='-')f = -f;s = getchar();}
	while(s >= '0' && s <= '9') {x=x*10+(s-'0');s = getchar();}
	return f * x;
}
int n,m,i,j,s,o,k;
vector<int> g0[MAXN];
int L[MAXN],R[MAXN],lR[MAXN],tim;
void dfs0(int x,int ff) {
	L[x] = ++ tim;
	for(int i = 0;i < (int)g0[x].size();i ++) {
		if(g0[x][i] != ff) dfs0(g0[x][i],x);
	}R[x] = tim; lR[L[x]] = R[x];
	return ;
}
vector<int> g[MAXN];
int d[MAXN],dfn[MAXN],rr[MAXN],cnt,ans;
set<int> st;
void dfs(int x,int ff) {
	int ad = 0;
	if(st.empty()) st.insert(L[x]);
	else {
		SI i = st.lower_bound(L[x]);
		if(i != st.begin()) {
			i --;
			if(lR[*i] >= R[x]) ad = *i,st.erase(ad),st.insert(L[x]);
			else {
				i ++;
				if(i == st.end() || *i > R[x]) st.insert(L[x]);
			}
		}
		else if(i == st.end() || *i > R[x]) st.insert(L[x]);
	}
	ans = max(ans,(int)st.size());
	for(int i = 0;i < (int)g[x].size();i ++) {
		if(g[x][i] != ff) 
			dfs(g[x][i],x);
	}
	if(st.find(L[x]) != st.end()) st.erase(L[x]);
	if(ad) st.insert(ad);
	return ;
}
int main() {
	int T = read();
	while(T --) {
		n = read();
		tim = 0; cnt = 0;
		st.clear();
		for(int i = 1;i <= n;i ++) {
			g0[i].clear();g[i].clear();lR[i] = 0;
		}
		for(int u, v, i = 2;i <= n;i ++) {
            u = read(); v = read();
			g[u].push_back(v);
            g[v].push_back(u);
		}
		for(int u, v, i = 2;i <= n;i ++) {
			u = read(); v = read();
			g0[u].push_back(v);
            g0[v].push_back(u);
		}
		dfs0(1,0);ans = 0;dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
