#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
struct nds{
	int x,y,z,t;
}a[1100000];
int n,m,t;
set <int> st;
int ans[210000];
int b[210000];
void work(int l,int r){
	st.clear();
	int sum=0;
	for(int i=l;i<=r;++i){
		if(a[i].z==1){
			b[a[i].x]=sum;
			st.insert(a[i].x);
		}
		else if(a[i].z==2){
			ans[a[i].x]+=sum-b[a[i].x];
			st.erase(a[i].x);
		}
		else{
			sum++;
		}
	}
	for(set <int>::iterator i=st.begin();i!=st.end();i++){
		ans[*i]+=sum-b[*i];
	}
}
bool cmp(nds x,nds y){
	return x.y == y.y ? x.t<y.t : x.y<y.y;
}
int main(){
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=t;++i){
		scanf("%d%d%d",&a[i].z,&a[i].x,&a[i].y);
		a[i].t=i;
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=m;++i){
		b[i]=-1;
	}
	int lst=0;
	a[t+1].y=-1;
	for(int i=1;i<=t;++i){
		if(a[i+1].y!=a[i].y){
			work(lst+1,i);
			lst=i;
		}
	}
	for(int i=1;i<=t;++i){
		if(a[i].z==3){
			ans[a[i].x]--;
		}
	}
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}
