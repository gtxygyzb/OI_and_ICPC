#include <bits/stdc++.h>
using namespace std;
const int N=1e5+50,P=1e9+7;

int s[100][100];
int S(int n,int m)
{
	if (m>n) return 0;
	if (m==1) {s[n][m]=1; return 1;}
	if (s[n][m]) return s[n][m];
	s[n][m]=S(n-1,m-1)+m*S(n-1,m);
	return s[n][m];
}
int power(int x,int k)
{
	int ret=1;
	for (;k;x=1LL*x*x%P,k>>=1)
		if (k&1) ret=1LL*ret*x%P;
	return ret;
}


int n,k;
int pri[N],top,vis[N],ans=1;
int fac[N]={1},invf[N]={1},mi[N];
void init()
{
	for (int i=1;i<=N-50;i++)
	{
		fac[i]=1LL*fac[i-1]*i%P;
		invf[i]=power(fac[i],P-2);
	}
	vis[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!vis[i]) {pri[++top]=i; mi[i]=i;}
		for (int j=1;j<=top&&pri[j]*i<=n;j++)
		{
			vis[i*pri[j]]=1;
			mi[i*pri[j]]=pri[j];
			if (i%pri[j]==0) break;
		}
	}
	for (int i=7;i>=1;i--)
		for (int j=7;j>=1;j--)
			s[i][j]=S(i,j);
}

int work(int x)
{
	int ret=0;
	while (x!=1)
	{
		if (mi[x]!=mi[x/mi[x]])
			++ret;
		x/=mi[x];
	}
	return ret;
}

int A(int k,int j)
{
	return 1LL*fac[k]*invf[k-j]%P;
}
int main()
{
	scanf("%d%d",&n,&k);
	init();
	for (int cnt,i=2;i<=n;i++)
	{
		cnt=work(i);
		int tmp=0;
		for (int j=1;j<=min(cnt,k);j++)
		{
			ans=(ans+1LL*A(k,j)*s[cnt][j]%P)%P;
			tmp+=1LL*A(k,j)*s[cnt][j];
		}
	}
	printf("%d\n",ans);
	return 0;
}

