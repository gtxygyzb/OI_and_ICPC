#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50, P = 998857459;
int n, m, fac[N] = {1}, a[N], nxt[N];
int val[N], ans[N], fa[N];
struct Query
{
    int val, pos;
    void input(int _pos) {scanf("%d", &val); pos = _pos;}
    bool operator <(const Query &t) const
    {
        return val < t.val;
    }
}q[N];
int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        fac[i] = 1LL * fac[i - 1] * i % P;
    int pre = 0, st = 0;
    for (int x, i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        a[i] = fac[x];
        if (a[i] != 0)
        {
            if (st == 0) st = i, pre = i;
            else
            {
                nxt[pre] = i;
                pre = i;
            }
        }
    }

    for (int i = 1; i <= m; i++)
        q[i].input(i);
    sort(q + 1, q + m + 1);
    for (int i = 1; i <= m; i++)
        val[i] = q[i].val;

    memset(ans, 0x3f, sizeof(ans));
    for (int i = st; i; i = nxt[i])
    {
        int sum = 0, len = 1;
        for (int j = i; j; j = nxt[j])
        {
            sum += a[j];
            if (sum >= P) sum -= P;
            int pos = upper_bound(val + 1, val + m + 1, sum) - val - 1;
            //cout<<i<<" "<<j<<" "<<sum<<" "<<len<<" "<<pos<<endl;
            ans[pos] = min(ans[pos], len);
            len += nxt[j] - j;
        }
    }
    for (int i = m - 1; i >= 1; i--)
        ans[i] = min(ans[i], ans[i + 1]);
    for (int i = 1; i <= m; i++)
        fa[q[i].pos] = ans[i];
    for (int i = 1; i <= m; i++)
        printf("%d\n", fa[i] == ans[m + 5] ? -1 : fa[i]);
    return 0;
}
/*
4 5
1 2 3 4
31 29  35 33 32
*/