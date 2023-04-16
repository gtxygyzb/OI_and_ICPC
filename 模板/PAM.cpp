//以一个点为结尾的回文串个数 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int ans;
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
    void add(int c)
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
        ans = cnt[last];
        printf("%d ", ans);
    }
}pam;

char c;
int main()
{
    while (c = getchar())
    {
        if (c < 'a' || c > 'z') break;
        c = (c - 97 + ans) % 26 + 97;
        pam.add(c);
    }
    return 0;
}
