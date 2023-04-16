#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6;
const ll N=19,M=1ll<<N;
ll s[maxn+5],p[maxn+5];
queue<ll>q[55];
void dfs(ll st,ll dq){
	ll i,j,k,cur,m=1ll<<dq;
	//cout<<st<<"|"<<dq<<"|"<<m<<endl;
	if(q[dq].size()>0){
		cur=q[dq].front(),q[dq].pop();
		for(i=st;i<=M;i+=m) p[i]=cur;
	}
	else{
		if(dq<=N){
			dfs(st,dq+1);
			dfs(st+m,dq+1);
		}	
	}
}
int main(){
	ll n,i,j,k,zc,dq;
	scanf("%lld",&n);
	for(i=1;i<=n;i++) scanf("%lld",&s[i]);
	for(i=1;i<=n;i++){
		zc=2,dq=1;
		while(zc*2<=s[i]) zc*=2,dq++;
		q[dq].push(i);
	}
	dfs(1,1),dfs(2,1);
	printf("%lld\n",M);
	for(i=1;i<=M;i++){
		if(p[i]==0) printf("1 ");
		else printf("%lld ",p[i]);
		//printf("%lld ",p[i]);
	}
	return 0;
}