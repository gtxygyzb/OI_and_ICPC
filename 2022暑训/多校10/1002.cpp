#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<unordered_map>
#include<cmath>
using namespace std;

typedef int ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 10;
const int mod = 998244353;

namespace Fibo {
    typedef long long LL;
    constexpr int P = 998244353;

    inline int Mod(const int& x) { return x + (x >> 31 & P); }
    inline int mns(const int& a, const int& b) { return Mod(a - b); }
    inline int pls(const int& a, const int& b) { return Mod(a + b - P); }
    inline int mul(const int& a, const int& b) { return 1LL * a * b % P; }

    int fpow(int base, int b) {
        int ret = 1;
        while (b > 0) {
            if (b & 1) ret = mul(ret, base);
            base = mul(base, base), b >>= 1;
        }
        return ret;
    }

    struct Int {
        int x, y; // x + sqrt{5} y
        Int(int _x = 0, int _y = 0) : x(_x), y(_y) { }
        Int operator + (const Int& rhs) const {
            return Int(pls(x, rhs.x), pls(y, rhs.y));
        }
        Int operator - (const Int& rhs) const {
            return Int(mns(x, rhs.x), mns(y, rhs.y));
        }
        Int operator * (const Int& rhs) const {
            int ac = mul(x, rhs.x), ad = mul(x, rhs.y), bc = mul(y, rhs.x);
            return Int(pls(ac, 5LL * y % P * rhs.y % P), pls(bc, ad));
        }
        Int operator / (const Int& rhs) const {
            int ac = mul(x, rhs.x), ad = mul(x, rhs.y), bc = mul(y, rhs.x);
            int iv = fpow(mns(mul(rhs.x, rhs.x), 5LL * rhs.y % P * rhs.y % P), P - 2);
            return Int(mns(ac, 5LL * y % P * rhs.y % P), mns(bc, ad)) * iv;
        }
        Int operator += (const Int& rhs) { return x = pls(x, rhs.x), y = pls(y, rhs.y), *this; }
        Int operator -= (const Int& rhs) { return x = mns(x, rhs.x), y = pls(y, rhs.y), *this; }
        Int operator *= (const Int& rhs) { return *this = *this * rhs; }
    };

    Int fpowInt(Int base, LL b) {
        Int ret = Int(1, 0);
        for (; b > 0; base *= base, b >>= 1)
            if (b & 1) ret *= base;
        return ret;
    }

    int calc(int n) {
        Int A = Int(0, 1) / 5;
        Int ret = A * (fpowInt(Int(1, 1) / 2, n) - fpowInt(Int(1, P - 1) / 2, n));
        return ret.x;
    }
}

namespace IO {
    const int MAXSIZE = 1 << 18 | 1;
    char buf[MAXSIZE], * p1, * p2;

    inline int Gc() {
        return p1 == p2 &&
            (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) ? EOF : *p1++;
    }
    template<typename T> inline void read(T& x) {
        x = 0; int f = 0, ch = Gc();
        while (!isdigit(ch)) f |= ch == '-', ch = Gc();
        while (isdigit(ch)) x = x * 10 + ch - '0', ch = Gc();
        if (f) x = -x;
    }

    inline int read(char* s) {
        int lgt = 0, ch = Gc();
        while (isspace(ch)) ch = Gc();
        while (!isspace(ch)) s[++lgt] = ch, ch = Gc();
        return s[lgt + 1] = '\0', lgt;
    }
}
using IO::read;

ll a[MAXN];
bool vis[MAXN];
ll dp[MAXN][2];

inline ll get(ll len,bool f)
{
    ll n = 2 * len - 1;
    if (f) n++;
    return Fibo::calc(n);
}

unordered_map<ll, ll> mpp[2];

inline ll add(ll x, ll y)
{
    if (x + y >= mod) return x + y - mod;
    return x + y;
}

void solve()
{
    int n, m;
    read(n); read(m);

    //scanf("%d%d", &n, &m);
    map<ll, ll> mp;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        read(x); read(y);
        ll mx = max(x, y), mn = min(x, y);
        ll nd = mx - mn + 1;
        if (mp[mn]) mp[mn] = max(mp[mn], nd);
        else mp[mn] = nd;
    }
    int cnt = 0;
    ll bg = -1, len = 0;
    bool f = 1;
    for (auto& p : mp)
    {
        if (f)
        {
            f = 0;
            bg = p.first;
            len = p.second;
            if (bg != 1)
            {
                a[++cnt] = bg - 1;
                vis[cnt] = 0;
            }
        }
        else
        {
            if (p.first >= bg + len)
            {
                a[++cnt] = len;
                vis[cnt] = 1;
                if (p.first - (bg + len - 1) > 0)
                {
                    a[++cnt] = p.first - (bg + len - 1);
                    vis[cnt] = 0;
                }
                bg = p.first;
                len = p.second;
            }
            else
            {
                len = max(len, p.first + p.second - bg);
            }
        }
    }
    a[++cnt] = len;
    vis[cnt] = 1;
    if (bg + len <= n)
    {
        a[++cnt] = (n - (bg + len - 1));
        vis[cnt] = 0;
    }
    dp[0][0] = 1; dp[0][1] = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (vis[i])
        {
            dp[i][0] = 0;
            dp[i][1] = add(dp[i - 1][0], add(dp[i - 1][1], dp[i - 1][1]));
            //dp[i][1] %= mod;
        }
        else
        {
            if (a[i] == 1)
            {
                dp[i][0] = add(dp[i - 1][0], dp[i - 1][1]);
            }
            else
            {
                ll nd1, nd2;
                if (mpp[0][a[i] - 1]) nd1 = mpp[0][a[i] - 1];
                else nd1 = mpp[0][a[i] - 1] = get(a[i] - 1, 0);
                if (mpp[1][a[i] - 1]) nd2 = mpp[1][a[i] - 1];
                else nd2 = mpp[1][a[i] - 1] = get(a[i] - 1, 1);
                dp[i][0] = add(1ll*dp[i - 1][0] * add(nd1,nd2) % mod , 1ll*dp[i - 1][1] * add(nd1 ,add(nd2,nd2) % mod));
            }
            if (a[i] == 1)
            {
                dp[i][1] = add(add(dp[i - 1][1], dp[i - 1][1]), dp[i - 1][0]);
                //dp[i][1] %= mod;
            }
            else
            {
                ll nd1, nd2;
                if (mpp[0][a[i]]) nd1 = mpp[0][a[i]];
                else nd1 = mpp[0][a[i]] = get(a[i], 0);
                if (mpp[1][a[i] - 1]) nd2 = mpp[1][a[i] - 1];
                else nd2 = mpp[1][a[i] - 1] = get(a[i] - 1, 1);
                dp[i][1] = add(1ll*nd1 * add(dp[i - 1][0], add(dp[i - 1][1], dp[i - 1][1])) % mod, 1ll*nd2 * add(dp[i - 1][0], dp[i - 1][1]) % mod);
                //dp[i][1] %= mod;
            }

        }
    }
    ll ans = add(dp[cnt][0], dp[cnt][1]);
   // ans %= mod;
    printf("%d\n", ans);
}

int main()
{
    int T = 1;
    read(T);
    //scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}
