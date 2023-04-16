#include <bits/stdc++.h>
using namespace std;
const int N = 3005, P = 1e9+7;
int C[N][N], ans, cnt[N];
int power(int x, int k)
{
    int ret = 1, a = x;
    for (;k ;k >>= 1, x = 1LL * x * x % P)
        if (k & 1) ret = 1LL * ret * x % P;
    return ret;
}
int main()
{
    string s; int c;
    cin>>s>>c;
    int n = s.size();
    C[0][0] = C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % P;
    }
    int pre = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
        {
            for (int j = 1; j < n - i; j++)
                cnt[pre + j] = (cnt[pre + j] + C[n-i-1][j]) % P;
            ++pre;
            cnt[pre] = (cnt[pre] + 1) % P;
        }
    for (int i = 1; i <= n; i++)
        ans = (ans + 1LL * power(c, i) * cnt[i] % P) % P;
    cout<<(ans+1)%P<<endl;
    return 0;
}