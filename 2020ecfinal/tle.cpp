#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50, M = 65, P = 998244353;
char s[N];
int n, t[M], top, sum;
int ans, ij[M], cnt[M], l[M], f[M], tot, pre[M];
int id(char c)
{
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return 26 + c - 'A';
    return 52 + c - '0';
}
void add(int &x, int y) {x += y; if (x >= P) x -= P;}
void del(int &x, int y) {x -= y; if (x < 0) x += P;}

inline int C(int x) {return (1LL * cnt[x] * (cnt[x] - 1) >> 1) % P;}
inline int calc(int x, int b, int i)
{
    int m = i - cnt[x] - cnt[b];
    int ret = ((1LL * m * (m - 1) >> 1)  - (sum - C(x) - C(b)) ) % P;
    if (ret < 0) return ret + P;
    return ret;
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int b = 0; b < 62; b++)
    {
        sum = tot = top = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++)
            ++cnt[id(s[i])];
        if (cnt[b] <= 1) continue;
        for (int i = 0; i < 62; i++)
            add(sum, C(i));
        memset(f, 0, sizeof(f));
        memset(l, 0, sizeof(f));
        memset(pre, 0, sizeof(pre));
        memset(ij, 0, sizeof(ij));
        for (int x, i = n; i >= 1; i--)
        {
            x = id(s[i]);
            del(sum, C(x));
            --cnt[x];
            add(sum, C(x));
            if (x == b)
            {
                ++tot;
                for (int j = 1; j <= top; j++)
                {
                    x = t[j];
                    int tmp = 1LL * l[x] * l[b] % P;
                    add(f[x], (tmp + 1LL * (tot - pre[x]) * ij[x] % P) % P);
                    add(ij[x], tmp);
                    l[x] = 0;
                    pre[x] = tot;
                }
                top = 0;
                ++l[b];
            }
            else
            {
                add(ans, 1LL * (f[x] + 1LL * (tot - pre[x]) * ij[x] % P) * calc(x, b, i - 1) % P);
                ++l[x];
                if (l[x] == 1)
                    t[++top] = x;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}