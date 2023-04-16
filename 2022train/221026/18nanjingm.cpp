#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 50;
const ull base = 131;

ull gap[N], hs[N], ht[N];
int n, m, suf[N];
void init()
{
    gap[0] = 1;
    for (int i = 1; i <= N - 50; i++)
        gap[i] = gap[i - 1] * base;
}
void gethash(char *s, ull *h)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        h[i + 1] = h[i] * base + (ull)(s[i] - 'a');
}
ull find(int l, int r, ull *h)
{
    return h[r + 1] - h[l] * gap[r - l + 1];
}

struct PAM
{
    int f[N], len[N], top, n, last;
    int ch[N][26], s[N], cnt[N];
    PAM ()
    {
        s[0] = -1; f[0] = 1;
        len[1] = -1; top = 1;
    }
    int getfail(int u)
    {
        while (s[n - len[u]  - 1] != s[n])
            u = f[u];
        return u;
    }
    int add(int c)
    {
        s[++n] = c;
        int u = getfail(last);
        int &v = ch[u][c];
        if (!v)
        {
            int np = ++top;
            len[np] = len[u] + 2;
            f[np] = ch[getfail(f[u])][c];
            cnt[np] = cnt[f[np]] + 1;
            v = np;
        }
        last = v;
        return cnt[last];
    }
}pam;
char s[N], t[N];
ll ans;
void solve()
{
    for (int i = 0; i < n - 1; i++)
    {
        int l = 1, r = i + 1, mx = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (find(i - mid + 1, i, hs) == find(m - mid, m - 1, ht))
                mx = mid, l = mid + 1;
            else r = mid - 1;
        }
        ans += 1ll * mx * suf[i + 1];
    }
    printf("%lld\n", ans);
}
int main()
{
    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    for (int i = n - 1; ~i; i--)
        suf[i] = pam.add(s[i] - 'a');
    reverse(t, t + m);
    init();
    gethash(s, hs);
    gethash(t, ht);
    solve();
    return 0;
}
/*
ababa
aba

aabbaa
aabb
*/