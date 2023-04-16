#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 19, M = 1e5 + 50;
int n, t[N], len[N], bin[N] = {1};

ll H, d[N][M], f[(1<<N) + 1];

void up(ll &x, ll y) {x = max(x, y);}
bool check(int lim)
{
    for (int i = 0; i < bin[n]; i++)
        f[i] = -1;
    f[0] = 0;
    for (int i = 0; i < bin[n]; i++)
    {
        if (f[i] < 0) continue;
        if (f[i] >= H) return 1;
        int frm = 0;
        for (int j = 0; j < n; j++)
            if (i & bin[j]) frm += t[j];
        if (frm > lim) continue;
        for (int j = 0; j < n; j++)
            if (!(i & bin[j]))
            {
                if (frm + len[j] - 1 <= lim) up(f[i | bin[j]], f[i] + d[j][len[j] - 1]);
                else up(f[i | bin[j]], f[i] + d[j][lim - frm]);
            }
    }
    return 0;

}
int main()
{
    for (int i = 1; i <= 18; i++)
        bin[i] = bin[i - 1] << 1;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int l = 0, r = 0, ans = -1;
        scanf("%d%lld", &n, &H);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", t+i, len+i);
            r += t[i] + len[i] - 1;
            for (int j = 0; j < len[i]; j++)
                scanf("%lld", &d[i][j]);
            for (int j = 1; j < len[i]; j++)
                d[i][j] += d[i][j - 1];
        }
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check(mid)) {ans = mid; r = mid - 1;}
            else l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}