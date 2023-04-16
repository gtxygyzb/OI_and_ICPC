#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
int main()
{
    scanf("%lld%lld", &a, &b);
    ll c = a ^ b;
    if (c < a)printf("1\n%lld\n", c);
    else
    {
        /*printf("")
        ll d;
        for (int k = 63; ~k; k--)
            if (c & (1LL<<k))
            {
                c ^= (1LL<<k);
                d = (1LL<<k);
                break;
            }*/
        printf("2\n%lld %lld\n", b, a);
    }
    return 0;
}