#include <bits/stdc++.h>
using namespace std;
const int N=1e6+50;
const int inf = 2e9+7;
int n,a[N],suma,ans;

int sum,mx,l[N],r[N];
int main()
{
	scanf("%d", &n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d", a+i);
		suma += a[i];
	}
	sum = -inf, mx = -inf;
	for (int i=1;i<=n;i++)
	{
		if (sum>0) sum+=a[i];
		else sum = a[i];
		mx = max(mx, sum);
		l[i] = mx;
	}
	sum = -inf, mx = -inf;
	for (int i=n;i>=1;i--)
	{
		if (sum>0) sum+=a[i];
		else sum = a[i];
		mx = max(mx, sum);
		r[i] = mx;
	}
	for (int i=1;i<n;i++)
		ans = max(max(max(l[i],r[i+1]),l[i]+r[i+1]),ans);
	printf("%d\n",suma+ans);
	return 0;
}

