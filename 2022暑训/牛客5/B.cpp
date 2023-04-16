#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef long long ll;
int n, m, a[N];
ll c[N];

bool check(int k)
{
    for (int i = 1; i <= n; i++)
        c[i] = a[i] + 1LL * k * i;
    sort(c + 1, c + n + 1);
    ll cur = 0, ret = 0;
    for (int i = 1; i <= n; i++)
        if (cur + c[i] <= m) {cur += c[i]; ++ret;}
    return ret >= k; 
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);
        int l = 1, r = n, ans = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check(mid)) {ans = mid; l = mid + 1;}
            else r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
4 5
3 4 5 6
*/