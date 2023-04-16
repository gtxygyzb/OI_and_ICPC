#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 550;
const ll P = 998244353;
int n;
ll a[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", a+i);
        ll ans = a[1];
        for (int i = 2; i <= n; i++)
            ans = (ans + a[i] + ans * a[i]) % P;
        printf("%lld\n", ans);
    }
    return 0;
}