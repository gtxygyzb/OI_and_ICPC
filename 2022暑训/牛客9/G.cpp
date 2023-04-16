#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6e5 + 50;

int k;

struct PAM
{
    int f[N], cnt[N][10], len[N], top, n, last;
    int ch[N][40], s[N];
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
    void add(int c, int id)
    {
        s[++n] = c;
        int u = getfail(last);
        int &v = ch[u][c];
        if (!v)
        {
            int np = ++top;
            len[np] = len[u] + 2;
            f[np] = ch[getfail(f[u])][c];
            v = np;
        }
        cnt[v][id] = 1;
        last = v;
    }
    void query()
    {
        int ans = 0;
        for (int i = top; i >= 2; i--)
        {
            int flag = 1;
            for (int j = 0; j < k; j++)
            {
                cnt[f[i]][j] |= cnt[i][j];
                flag &= cnt[i][j];
            }
            ans += flag;
        }
        printf("%d\n", ans);
    }
}pam;

char s[N];
int main()
{
    scanf("%d", &k);
    for (int id = 0; id < k; id++)
    {
        if (id > 0)
        {
            pam.add(27 + id * 2, id);
            pam.add(27 + id * 2 + 1, id);
        }
        scanf("%s", s);
        for (int len = strlen(s), i = 0; i < len; i++)
            pam.add(s[i] - 'a', id);
    }
	pam.query();
	return 0;
}
/*
1
asdads
*/