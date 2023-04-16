#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d", &n, &m);
	if (n==1)
	{
		printf("%d\n", m);
		return 0;
	}
	if (n==2)
	{
		printf("%d\n", m-2);
		return 0;
	}
	m-=n*2;
	while (m<(n-1)/2)
	{
		m+=2;
		n-=1;
	}
	if (m==(n-1)/2) printf("%d\n", 3);
	else printf("%d\n", m-(n-1)/2+2);
	return 0;
}

