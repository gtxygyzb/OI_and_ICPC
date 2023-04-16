#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50, P = 998244353;
int n;
ll a[N];
ll bin[61] = {1};

int main()
{
    for (int i = 1; i <= 60; i++)
        bin[i] = bin[i-1] << 1;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d", &n);
        for (int i = 1; i <= n ; i++)
            scanf("%lld", a+i);
        scanf("%d", &m);
        for (int opt, l, r; m--;)
        {
            scanf("%d%d%d", &opt, &l, &r);
            if (opt == 2)
            {
                for (int i = l; i <= r; i++)
                    a[i] -= a[i] & - a[i];
            }
            if (opt == 3)
            {
                for (int i = l; i <= r; i++)
                {
                    for (int j = 60; j >= 0; j--)
                        if (a[i] & bin[j])
                        {
                            a[i] = a[i] + bin[j];
                            break;
                        }
                }
            }
            if (opt == 1)
            {
                ll ret = 0;
                for (int i = l; i <= r; i++)
                    ret = (ret + a[i]) % P;
                printf("%lld\n", ret);
            }
        }
    }
    return 0;
}
/*
1
1
536870912
3
3 1 1
3 1 1
1 1 1
*/