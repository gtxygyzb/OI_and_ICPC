#include <bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int st[N],top,tmp[N],siz;
int main()
{
	int T;
	scanf("%d",&T);
	for (int n,k;T--;)
	{
		scanf("%d%d",&n,&k);
		if (k==1)
		{
			puts("0");
			continue;
		}
		if (n<=k)
		{
			printf("%d\n",n-1);
			for (int i=2;i<=n;i++)
			{
				printf("%d",i);
				printf(i==n ? "\n" : " ") ;
			}
			continue;
		}
		int st1=k,st2=1+k+2*(k-1);
		if (n<=st2)
		{
			for (int i=1;i<=n;i++)
				st[n-i+1]=i;
			top=n;
			int num=n;
			while (top)
			{
				while (st[top]==0&&top) --top;
				--top; --num;
				if (top==0||num<k) break;
				for (int i=top,cnt=0;i;i--)
				{
					if (st[i]) ++cnt;
					if (cnt==k) st[i]=0;
				}
				--num;
			}
			printf("%d\n",num);
			if (num)
			{
				for (int cnt=0,i=top;i>=1;i--)
					if (st[i])
					{
						++cnt;
						printf("%d",st[i]);
						printf(cnt==num ? "\n" : " ") ;
					}
			}
		}
		else
		{
			if ((n+k)&1)
			{
				printf("%d\n",k-2);
				
				for (int i=n-1,j=1;j<=k-2;i-=2,j++)
					tmp[j]=i;
				for (int i=k-2;i>=1;i--)
				{
					printf("%d",tmp[i]);
					printf(i==1 ? "\n" : " ") ;
				}
			}
			else
			{
				printf("%d\n",k-1);
				for (int i=n,j=1;j<=k-1;i-=2,j++)
					tmp[j]=i;
				for (int i=k-1;i>=1;i--)
				{
					printf("%d",tmp[i]);
					printf(i==1 ? "\n" : " ") ;
				}
			}
		}
	}
	return 0;
}

