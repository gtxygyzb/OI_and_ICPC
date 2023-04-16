#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;
int n, a[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int xq, yq, xz, yz;
        scanf("%d%d%d%d", &xq, &yq, &xz, &yz);
        ++a[xq]; --a[xz + 1];
    }
    int cur = 0, ans = 0;
    for (int i = 1; i <= N - 50; i++)
    {
        cur += a[i];
        if (cur > 0) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}