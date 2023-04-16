#include<iostream>
#include<cstdio>
using namespace std;
struct edg{
	int nxt,y;
	double z;
}e[410000];
int lk[210000],lt=0;
void ist(int x,int y,int z){
	e[++lt]=(edg){lk[x],y,z};
	lk[x]=lt;
	e[++lt]=(edg){lk[y],x,z};
	lk[y]=lt;
}
int n;
int a[3][210000],at[3];
int b[210000];
int c[210000];
int f[210000];
double s[210000];
double dfs1(int x,int y){
	double sum=0;
	for(int i=lk[x];i;i=e[i].nxt){
		if(e[i].y==y)  continue;
		sum+=dfs1(e[i].y,x);
		sum+=f[e[i].y]*e[i].z;
		f[x]+=f[e[i].y];
	}
	if(b[x])  f[x]++;
	return sum;
}
double dfs2(int x,int y,int an){
	double sum=0;
	if(c[x]==1)  sum+=s[x];
	for(int i=lk[x];i;i=e[i].nxt){
		if(e[i].y==y)  continue;
		s[e[i].y]=s[x]+(an-2*f[e[i].y])*e[i].z;
		sum+=dfs2(e[i].y,x,an);
	}
	return sum;
}
double work(int n1,int a1[],int n2,int a2[]){
	for(int i=1;i<=n;++i){
		b[i]=0;
		c[i]=0;
		f[i]=0;
		s[i]=0;
	}
	for(int i=1;i<=n1;++i)  b[a1[i]]=1;
	for(int i=1;i<=n2;++i)	c[a2[i]]=1;
	s[1]=dfs1(1,0);
	return dfs2(1,0,n1)/((double)n1*n2);
}
int main(){
	scanf("%d",&n);
	int x,y,z;
	for(int i=1;i<n;++i){
		scanf("%d%d%d",&x,&y,&z);
		ist(x,y,z);
	}
	for(int i=0;i<3;++i){
		scanf("%d",&at[i]);
		for(int j=1;j<=at[i];++j){
			scanf("%d",&a[i][j]);
		}
	}
	double ans=0;
	ans+=work(at[0],a[0],at[1],a[1]);
	ans+=work(at[0],a[0],at[2],a[2]);
	ans+=work(at[1],a[1],at[2],a[2]);
	printf("%.8lf\n",ans/2);
	return 0;
}

