#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
int n;
ll p, sg[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%lld", &n, &p);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll l, r;
            scanf("%lld%lld", &l, &r);
            ll x = r;
            while ((x - 1) % p == 0 && (x - 1) / p >= l && x >= l)
                {x = (x - 1) / p; --x;}
            sg[i] = x - l + 1;
            //cout<<"qian: "<<sg[i]<<endl;
            if (x > l * p)
            {
                x -= l * p + 1;
                sg[i] -= x / p + 1;
            }
            ans ^= sg[i];
            //cout<<"sg: "<<sg[i]<<endl;
        }
        puts(ans ? "First" : "Second");
    }
    return 0;
}
/*
1
16 2
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
1 14
1 15
1 16
*/