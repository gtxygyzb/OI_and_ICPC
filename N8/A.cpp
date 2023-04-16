#include <bits/stdc++.h>
using namespace std;
const int P = 4933;
int n, m, k, a, l;
int power(int x, int k)
{
    int ret = 1;
    for (;k; k >>= 1, x = 1LL * x * x %P)
        if (k & 1) ret = 1LL * ret * x %P;
    return ret;
}
int main()
{
    scanf("%d%d%d%d%d", &n, &m, &k, &a, &l);
    a %= P;
    int tmp = 1;
    for (int x, y, z, i = 1; i <= k; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        if (x == 0) continue;
        y = z - y;
        tmp = 1LL * tmp * y % P * power(z, P-2) % P;
    }
    cout<<(a + tmp)%P<<endl;
    return 0;
}