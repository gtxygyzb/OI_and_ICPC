#include<cstdio>
int read(){
    int n=0;char c=getchar();bool f=0;
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-'){f=1;c=getchar();}
    while(c>='0'&&c<='9'){n=n*10+c-'0';c=getchar();}
    if(f)return -n;
    return n;
}
int max(int a,int b){
    if(a<b)return b;
    return a;
}
const int N=500007;
int n,s,t;
int head[N],nx[N*2],ver[N*2],tot;
void add(int a,int b){
    tot++;
    ver[tot]=b;
    nx[tot]=head[a];
    head[a]=tot;
    tot++;
    ver[tot]=a;
    nx[tot]=head[b];
    head[b]=tot;
}
int pa[N],dep[N],dm[N];
void dfs(int id){
    for(int i=head[id];i;i=nx[i]){
        if(pa[ver[i]])continue;
        pa[ver[i]]=id;
        dep[ver[i]]=dep[id]+1;
        dfs(ver[i]);
    }
}
void dfs2(int id){
    int mx=dep[id];
    for(int i=head[id];i;i=nx[i]){
        if(pa[ver[i]]!=id)continue;
        dfs2(ver[i]);
        mx=max(mx,dm[ver[i]]);
    }
    dm[id]=mx;
}
int a[N],b[N];
bool tag[N];
int search(int p1,int p2,bool f,int &ma,int &mb){
    if(p1==p2-1){
        ma=0;
        mb=0;
        return a[p1]-b[p2];
    }
    if(f){
        int v=search(p1,p2-1,0,ma,mb);
        ma=max(ma,a[p2-1]);
        mb=max(mb,b[p2-1]);
        int v2=max(a[p1],ma)-b[p2];
        if(v2<v)return v2;
        else return v;
    }else{
        int v=search(p1+1,p2,1,ma,mb);
        ma=max(ma,a[p1+1]);
        mb=max(mb,b[p1+1]);
        int v2=a[p1]-max(b[p2],mb);
        if(v2>v)return v2;
        else return v;
    }
}
int main(){
    n=read();s=read();t=read();
    for(int i=1;i<n;i++){
        int a,b;
        a=read();b=read();
        add(a,b);
    }
    pa[s]=-1;
    dfs(s);
    dfs2(s);
    int p=t;
    int len=0;
    while(p!=-1){
        tag[p]=1;
        int mx=dep[p];
        for(int i=head[p];i;i=nx[i]){
            if(tag[ver[i]])continue;
            if(pa[ver[i]]!=p)continue;
            if(dm[ver[i]]>mx)mx=dm[ver[i]];
        }
        mx-=dep[p];
        len++;
        a[len]=mx;
        p=pa[p];
    }
    for(int i=1;i<=len;i++){
        b[i]=a[len-i+1];
    }
    for(int i=1;i<=len;i++){
        a[i]=b[i];
    }
    for(int i=1;i<=len;i++){
        a[i]+=i;
        b[len-i+1]+=i;
    }
    int ma=0,mb=0;
    int ans=search(1,len,0,ma,mb);
    printf("%d\n",ans);
}