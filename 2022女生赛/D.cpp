#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;
ll a[N], sum, mi = 1e18;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", a+i);
		if (i > 1) sum += max(a[i], a[i - 1]);
	}
	cout<<sum<<endl;
	
	return 0;
}

