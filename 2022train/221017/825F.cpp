#include <bits/stdc++.h>
using namespace std;
const int N = 8050;
int nxt[N], cnt[N][N];
int num(int x)
{
    int ret = 0;
    for (; x; x /= 10) ++ret;
    return ret;
}
void getnxt(char *s, int st)
{
    int m = strlen(s);
    memset(nxt, 0, sizeof(nxt));
    cnt[st][st] = 2;
    for (int j = 0, i = 2; i <= m; i++)
    {
        while (j && s[i - 1] != s[j]) j = nxt[j];
        if (s[i - 1] == s[j]) nxt[i] = ++j;
        if (nxt[i] && (i % (i - nxt[i]) == 0))
        {
            //cout<<"yes:"<<i<<" "<<nxt[i]<<endl;
            cnt[st][st + i - 1] = num(i / (i - nxt[i])) + i - nxt[i];
        }
        else cnt[st][st + i - 1] = i + 1;
        //cout<<st<<", "<<st + i - 1<<": "<<cnt[st][st + i - 1]<<endl;
    }
}
int n, f[N];
char s[N];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        getnxt(s + i, i);
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            f[i] = min(f[i], f[j] + cnt[j + 1][i]);
    printf("%d\n", f[n]);
    return 0;
}