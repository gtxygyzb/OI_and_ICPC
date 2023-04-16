#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n;
int prm[1100000],prf[1100000],prt=0;
void gtp(){
	for(int i=2;i<=1000000;++i){
		if(prf[i]==0)  prm[++prt]=i;
		for(int j=1;j<=prt && prm[j]*i<=1000000;++j){
			prf[i*prm[j]]=1;
			if(i%prm[j]==0)  break;
		}
	}
}
bool chc(long long x){
	long long s=sqrt(x);
	for(int i=-3;i<=3;++i){
		if((s+i)*(s+i)==x){
			return true;
		}
	}
	return false;
}
int main(){
	gtp();
	int T;  scanf("%d",&T);
	while(T --> 0){
		scanf("%lld",&n);
		int mk=0;
		for(int i=1;i<=prt && prm[i]<=n;++i){
			if(n%prm[i]==0){
				n/=prm[i];
				if(n%prm[i]==0){
					mk=1;
					break;
				}
			}
		}
		if(n!=1 && chc(n))  mk=1;
		if(mk==1)  printf("yes\n");
		else  printf("no\n");
	}
	return 0;
}
