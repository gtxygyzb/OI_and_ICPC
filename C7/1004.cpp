#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e6 + 10;
const int mod = 1e9 + 7;


int T;
int n, m;
ll jc[MAXN], inv[MAXN];

ll ksm(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
        {
            ans = ans * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}

ll C(int x, int y)
{
    return jc[x] * inv[x - y] % mod * inv[y] % mod;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("test.in", "r", stdin);
    jc[0] = 1;
    jc[1] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
        jc[i] = jc[i - 1] * i % mod;
    }
    inv[MAXN - 1] = ksm(jc[MAXN - 1], mod - 2);
    for (ll i = MAXN - 2; i >= 1; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    inv[0] = 1;
    cin >> T;

    while (T--)
    {
        cin >> n >> m;

        cout << C(m + n - 1, n - 1) * 2 % mod << "\n";
    }


    return 0;
}