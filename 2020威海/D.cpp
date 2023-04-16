#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 50;
int n;
ll a[N];
int check(ll lim)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] < lim) sum += lim - 1 - a[i];
    return sum < lim;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        ll l = 0, r = 4e9, ans = 1;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            if (check(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        printf("Case #%d: %lld\n", cs, ans);
    }
    return 0;
}
/*
5
3
1 2 3
4
0 0 0 0
*/