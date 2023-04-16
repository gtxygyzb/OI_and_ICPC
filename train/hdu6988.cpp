#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;

int n, val[N];
ll k, sum[N];

struct SAM
{
    int ch[N][26], mx[N], fa[N], top, last;
    int pos[N];
    void init()
    {
        for (int i = 1; i <= top; i++)
            for (int j = 0; j < 26; j++)
                ch[i][j] = 0;
        last = top = 1;
    }
    void add(int c, int id)
    {
        int p = last, np = last = ++top;
        mx[np] = mx[p] + 1;
        pos[np] = id;
        for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
        if (!p) fa[np] = 1;
        else
        {
            int q = ch[p][c];
            if (mx[q] == mx[p] + 1)
            {
                fa[np] = q;
            }
            else
            {
                int nq = ++top; mx[nq] = mx[p] + 1;
                memcpy(ch[nq], ch[q], sizeof(ch[nq]));
                fa[nq] = fa[q];
                pos[nq] = id;
                fa[q] = fa[np] = nq;
                for (; ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
            }
        }
    }

    void add_string(char *s)
    {
        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + val[s[i] - 'a'];
            add(s[i] - 'a', i + 1);
        }
    }
    bool check(int lim)
    {
        ll ret = 0;
        for (int i = 2; i <= top; i++)
        {
            int p = pos[i];
            int l = mx[i], r = mx[fa[i]] + 1, ans = -1;
            while (r <= l)
            {
                int mid = l + r >> 1;
                if (sum[p] - sum[p - mid] <= lim) {ans = mid; r = mid + 1;}
                else l = mid - 1;
            }
            if (~ans) ret += ans - mx[fa[i]];
        }
        return ret >= k;
    }
    void work()
    {
        ll tot = 0;
        for (int i = 1; i <= top; i++)
            tot += mx[i] - mx[fa[i]];
        if (k > tot)
        {
            puts("-1");
            return ;
        }
        int l = 1, r = sum[n], ans;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid)) {r = mid; ans = r;}
            else l = mid + 1;
        }
        printf("%d\n", ans);
    }
}S;


char s[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%lld", &n, &k);
        scanf("%s", s);
        for (int i = 0; i < 26; i++)
            scanf("%d", val + i);
        S.init();
        S.add_string(s);
        S.work();
    }
    return 0;
}
/*
1
5 5
ababc
3 1 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/