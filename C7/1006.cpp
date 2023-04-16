#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
typedef long long ll;

int power(int x, int k)
{
    int ret = 1;
    for (; k; k >>= 1, x = 1LL * x * x % P)
        if (k&1) ret = 1LL * ret * x % P;
    return ret;
}
int main()
{
    int T, t, v, r;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &t, &v, &r);
        ll top = 1LL*v * v * t * t + 1LL*25*t*t*t*t - 1LL*r * r;
        ll bum = 1LL*10 * t * t * t * v;
        if (top >= bum) puts("1");
        else if (abs(top) >= bum) puts("0");
        else
        {
            top = (top % P + P) % P; bum %= P;
            ll ans = 1LL * top * power(bum, P-2) % P;
            printf("%lld\n", 1LL * (ans + 1) * power(2, P - 2) % P);
        }
        //cout<<top<<" "<<bum<<endl;
    }
    return 0;
}