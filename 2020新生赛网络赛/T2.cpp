#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
	scanf("%d",&T);
	for (int n,k;T--;)
	{
		scanf("%d%d",&n,&k);
		int tmp=n/k*k;
		printf("%d\n",n-tmp);
		for (int i=tmp+1;i<=n;i++)
		{
			printf("%d",i);
			if (i!=n) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}

