#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
const int N = 2e6 + 50;
int A, B, a[10], b[10], ans, n;
int fac[N], inv[N], invt;

int power(int x, int k)
{
    int ret = 1;
    for (; k; k >>= 1, x = 1LL * x * x % P)
        if (k & 1) ret = 1LL * ret * x % P;
    return ret;
}
int Bi(int n, int k)
{
    if (k > n) return 0;
    //cout<<invt<<" "<<fac[n]<<" "<<inv[k]<<endl;
    return 1LL * invt * fac[n] % P * inv[k] % P * inv[n - k] % P;
}

int main()
{
    scanf("%d", &A);
    for (int i = 1; i <= 7; i++)
        scanf("%d", a+i);
    scanf("%d", &B);
    for (int i = 1; i <= 7; i++)
        scanf("%d", b+i);
    n = ceil(A / 10.0) + ceil(B / 10.0) - 1;
    //cout<<n<<endl;
    n = (A - 1) / 10 + (B - 1) / 10 + 1;
    //cout<<n<<endl;
    invt = power(power(2, n), P - 2);

    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = 1ll * fac[i - 1] * i % P;
        inv[i] = power(fac[i], P - 2);
    }
    for (int lim = (A - 1) / 10, i = 0; i <= lim; i++)
    {
        //cout<<"n, i"<<n<<" "<<i<<" "<<Bi(n, i)<<endl;
        ans += Bi(n, i);
        if (ans >= P) ans -= P;
    }
    printf("%d\n", ans);
    return 0;
}
/*
30 5 0 0 0 0 0 0
30 5 0 0 0 0 0 0
*/