#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool gcd(ll a, ll b, ll x)
{
    //cout<<a<<" "<<b<<" "<<x<<endl;
    if (b == x || a == x) return 1;
    if (b == 0) return 0;
    if (a % b == x) return 1;
    if (x < a && (x - a % b)%b == 0) return 1;
    return gcd(b, a % b, x);
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        ll a, b, x;
        
        scanf("%lld%lld%lld", &a, &b, &x);
        puts(gcd(a, b, x) ? "YES" : "NO");
    }
    return 0;
}
/*
1
365 216 52
*/