#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
int n, a[N], pos[N], mi[N], mx[N];
ll ans;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a+i);
            pos[a[i]] = i;
        }
        mx[0] = mi[0] = pos[0];
        for (int i = 1; i < n; i++)
        {
            mx[i] = max(mx[i - 1], pos[i]);
            mi[i] = min(mi[i - 1], pos[i]);
        }
        for (int len = 1; len <= n; len++)
        {
            int l = mi[(len - 1) >> 1], r = mx[(len - 1) >> 1];
            if (r - l + 1 > len) continue;
            int d = len - (r - l + 1);
            //cout<<l<<" "<<r<<" :"<<l<<" "<<n - r + 1<<" "<<d + 1<<endl;
            ans += d + 1 - max(0, r + d - n) + min(0, l - d - 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
1
4
2 0 1 3
*/