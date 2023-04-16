#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int T,n,m,num[N],d[N];
ll t[N],f[N],g[N];
struct Node{
	int l,r,opt;
}a[N];
struct Query{
	int p,x,id;
}q[N];
int main(){
	for(cin>>T;T;T--){
		cin>>n>>m;
		int cnt=0,_n=0;
		for(int i=1,p,x;i<=n;i++){
			scanf("%d%d",&p,&x);
			a[++_n]=Node{p-x,p,1};
			a[++_n]=Node{p,p+x,-1};//拆成两段差分
			num[++cnt]=p-x,num[++cnt]=p,num[++cnt]=p+x;
			q[i]=Query{p,x,0};
		}
		sort(num+1,num+cnt+1);
		cnt=unique(num+1,num+cnt+1)-num-1;
		for(int i=1;i<=cnt;i++)
			d[i]=0;
		for(int i=1;i<=_n;i++){
			a[i].l=lower_bound(num+1,num+cnt+1,a[i].l)-num;
			a[i].r=lower_bound(num+1,num+cnt+1,a[i].r)-num;
			d[a[i].l]+=a[i].opt,d[a[i].r]-=a[i].opt;//注意这里是差分每一段，所以是a[i].r不是a[i].r+1
		}
		for(int i=1;i<=n;i++)
			q[i].id=lower_bound(num+1,num+cnt+1,q[i].p)-num;
		for(int i=1;i<cnt;i++)
			d[i]+=d[i-1];
		for(int i=2;i<=cnt;i++)
			t[i]=t[i-1]+1ll*(num[i]-num[i-1])*d[i-1];
		for(int i=1;i<=cnt;i++)
        {
			t[i]=max(0ll,t[i]-m);
            cout<<t[i]<<" ";
        }
        puts("");
		f[0]=-1e18;
		for(int i=1;i<=cnt;i++){
			if(t[i]>0)f[i]=max(f[i-1],t[i]-num[i]);
			else f[i]=f[i-1];
		}
		g[cnt+1]=-1e18;
		for(int i=cnt;i>=1;i--){
			if(t[i]>0)g[i]=max(g[i+1],t[i]+num[i]);
			else g[i]=g[i+1];
		}
		for(int i=1;i<=n;i++)
			putchar((q[i].x-q[i].p>=f[q[i].id]&&q[i].x+q[i].p>=g[q[i].id])?'1':'0');
		puts("");
	}
	return 0;
}