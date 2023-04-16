#include <bits/stdc++.h>
using namespace std;

const int N = 7e5 + 50;

int n, pos[N], k;

struct SAM
{
    int fa[N], ch[N][26], mx[N], last, top, cnt[N];
    int t[N], rk[N];

    void init()
    {
        for (int i = 0; i <= top; i++)
        {
            fa[i] = mx[i] = cnt[i] = rk[i] = t[i] = 0;
            memset(ch[i], 0, sizeof(ch[i]));
        }
        last = top = 1;
    }
    void add(int c)
    {
        int p = last, np = last = ++top;
        mx[np] = mx[p] + 1; cnt[np] = 1;
        for (; !ch[p][c] && p; p = fa[p])
            ch[p][c] = np;
        if (!p) fa[np] = 1;
        else
        {
            int q = ch[p][c];
            if (mx[q] == mx[p] + 1)
                fa[np] = q;
            else
            {
                int nq = ++top;
                fa[nq] = fa[q];
                mx[nq] = mx[p] + 1;
                fa[q] = fa[np] = nq;
                memcpy(ch[nq], ch[q], sizeof(ch[nq]));
                for (; ch[p][c] == q; p = fa[p])
                    ch[p][c] = nq;
            }
        }
    }
    void query()
    {
        for (int i = 1; i <= top; i++) ++t[mx[i]];
        for (int i = 1; i <= top; i++) t[i] += t[i - 1];
        for (int i = top; i >= 1; i--)
            rk[t[mx[i]]--] = i;
        for (int i = top; i >= 1; i--)
        {
            int u = rk[i];
            cnt[fa[u]] += cnt[u];
            if (cnt[u] == k)
            {
                ++pos[mx[fa[u]] + 1];
                --pos[mx[u] + 1];
            }
        }
        int ans = -1, mx = 0, cur = 0;
        for (int i = 1; i <= n; i++)
        {
            cur += pos[i];
            if (cur >= mx)
                mx = cur, ans = i;
        }
        if (mx == 0) puts("-1");
        else printf("%d\n", ans);
    }
}sam;

char s[N];
void init()
{
    sam.init();
    for (int i = 0; i <= n; i++)
        pos[i] = 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        n = strlen(s);
        scanf("%d", &k);
        init();
        for (int i = 0; i < n; i++)
            sam.add(s[i] - 'a');
        sam.query();
    }
    return 0;
}