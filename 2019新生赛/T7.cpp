#include <bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int a[N],n,sum,num,ans[N],top;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		sum^=a[i];
	}
	if (n==1) return 0*puts("-1");
	if (sum==0) return 0*printf("2\n%d\n",n-1);
	num=sum;
	sum=0;
	for (int i=1;i<=n;i++)
	{
		sum^=a[i];
		if (sum==num)
		{
			sum=0;
			ans[++top]=i;
		}
	}
	if (top==1) return 0*puts("-1");
	printf("%d\n",top);
	for (int i=1;i<top;i++)
		printf("%d ",ans[i]);
	return 0;
}
