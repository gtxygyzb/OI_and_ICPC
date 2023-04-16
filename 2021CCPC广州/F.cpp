#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 50, P = 998244353;
ll f[N];
int main()
{
    int n;
    scanf("%d", &n);
    f[1] = 1; f[2] = 1;
    if (n < 3) return 0 * puts("1");
    for (int i = 3; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % P;
    printf("%d\n", f[n]);
    return 0;
}