#include <bits/stdc++.h>
using namespace std;
int ans;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for (int x,y,p;m--;)
	{
		scanf("%d%d%d",&x,&y,&p);
		if (p==1)
			ans=max(ans,x);
		if (p==2)
			ans=max(ans,n-y+1);
		if (p==3)
			ans=max(ans,n-x+1);
		if (p==4)
			ans=max(ans,y);
	}
	cout<<ans;
	return 0;
}
/*
2 2
1 1 1
2 2 3
*/
