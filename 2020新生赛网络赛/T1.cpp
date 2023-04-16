#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans,suma;
int main()
{
	scanf("%d",&n);
	for (int a,i=1;i<=n;i++)
	{
		scanf("%d",&a);
		suma+=a;
	}
	for (int b,i=1;i<=n;i++)
	{
		scanf("%d",&b);
		ans+=suma*b;
	}
	cout<<ans<<endl;
	return 0;
}

