// ### jxnu_1

#include<bits/stdc++.h>

using namespace std;
#define PI pair<int,int>
const int mod=998244353;
const int maxm=2e6+5;
const int block=1e3;
struct Node{
  int l,r,id,x;
}Q[maxm];
vector<int>g[maxm];
int res[maxm];
int a[maxm];
int cnt[maxm];
int num[maxm];
int ma=0;
int n,q;
bool cmp(Node a,Node b){
  if(a.x!=b.x)return a.x<b.x;
  return a.r<b.r;
}
void init(){
  for(int i=1;i<=n;i++)g[i].clear();
  for(int i=1;i<=n;i++){
    int x=a[i];
    for(int j=2;j*j<=x;j++){
      if(x%j==0){
        int c=0;
        while(x%j==0)x/=j,c++;
        g[i].push_back(j);
      }
    }
    if(x!=1){
      g[i].push_back(x);
    }
  }
}
void add(int x){
  for(auto v:g[x]){
    cnt[v]++;
    num[cnt[v]]++;
    if(num[cnt[v]]==1)ma++;
  }
}
void del(int x){
  for(auto v:g[x]){
    num[cnt[v]]--;
    if(num[cnt[v]]==0)ma--;
    cnt[v]--;
  }
}
void solve(){
  scanf("%d%d",&n,&q);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  //
  init();
  for(int i=1;i<=q;i++){
    int l,r;scanf("%d%d",&l,&r);
    Q[i]={l,r,i,l/block};
  }
  sort(Q+1,Q+1+q,cmp);
  int l=Q[1].l,r=l-1;
  for(int i=1;i<=q;i++){
    // cout<<i<<endl;
    int ql=Q[i].l,qr=Q[i].r;
    while(l<ql){
      del(l++);
    }
    while(l>ql){
      add(--l);
    }
    while(r<qr){
      add(++r);
    }
    while(r>qr){
      del(r--);
    }
    res[Q[i].id]=ma;
  }
  while(l<=r){//clear
    del(r--);
  }
  for(int i=1;i<=q;i++){
    printf("%d\n",res[i]);
  }
}
int main(){
  // freopen("in.txt","r",stdin);
  int T;cin>>T;while(T--)
  solve();
  return 0;
}