#include <bits/stdc++.h>
using namespace std;

int to(char c)
{
	if(c>='2'&&c<='9') return c-'1';
	if(c=='T') return 9;
	if(c=='J') return 10;
	if(c=='Q') return 11;
	if(c=='K') return 12;
	return 13;
}

int a[100],b[100];
char s[100];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			a[i]=to(s[0]);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%s",s);
			b[i]=to(s[0]);
		}
		scanf("%s",s);
		int p=to(s[0]);
		bool f=0;
		int cnta0=0,cntb0=0,cnta1=0,cntb1=0,mxa=-1,mxb=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<p) cnta0++;
			else cnta1++;
			mxa=max(mxa,a[i]);
		}
		for(int i=1;i<=m;i++)
		{
			if(b[i]<p) cntb0++;
			else cntb1++;
			mxb=max(mxb,b[i]);
		}
		if(n==1||cnta0==0) f=0;
		else if(cntb0>=2) f=1;
		else if(cntb0==0) f=0;
		else
		{
			int bb=0;
			for(int i=1;i<=m;i++){
				if(b[i]<p)
				{
					bb=b[i];
					break;
				}
			}
			bool ff=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]<p&&a[i]>=bb) ff=1;
			}
			if(!ff) f=0;
			else if(cntb1==0) f=1;
			else if(mxa<=mxb) f=0;
			else if(cnta0==1) f=0;
			else if(n<=3) f=0;
			else f=1;
		}
		if(f) puts("Pang");
		else puts("Shou");
	}

	return 0;
}

