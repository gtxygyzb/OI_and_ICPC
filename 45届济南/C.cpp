#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    ll mi = min(a, b);
    a -= mi;
    b -= mi;
    ll ans = mi * 2;
        if (a > 1)
        {
            ll del = a / 3 * 3;
            ans += del + ((a - del == 2) ? 1 : 0);
        }
        if (b > 1)
        {
            ll del = b / 3 * 3;
            ans += del * 2 + ((b - del == 2) ? 4 : 0);
        }
        cout<<ans;
    return 0;
}