#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h, m, a;
int main()
{
    scanf("%lld%lld%lld", &h, &m, &a);
    ll x = h - 1, mul = h * m;
    ll g = __gcd(x, mul);
    ll ans1 = a / g + 1;
    ll l = mul - a, r = mul - 1;
    ll ans2 = (r - l + 1);
    if (l % g != 0) ans2 -= g - l % g;
    if (ans2 > 0) ans2 = (ans2 - 1) / g + 1;

    if (mul - a == a && a % g == 0) --ans2;
    
    cout<<(ans1 + ans2) * g <<endl;
    return 0;
}