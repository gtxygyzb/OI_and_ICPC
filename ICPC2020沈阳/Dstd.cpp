#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int n, lim, cnt;
char s[N];
void dfs(int u, int ou, int ji, int yh)
{
    if (ou > lim || ji > lim)
        return ;
    if (u == n)
    {
        s[u] = '\0';
        printf("%s\n", s);
        ++cnt;
        if (cnt == 100) exit(0);
    }
    s[u] = 'b';
    dfs(u + 1, ou + (yh ^1), ji + yh, yh);
    yh ^= 1;
    s[u] = 'r';
    dfs(u + 1, ou + (yh ^1), ji + yh, yh);
}
int main()
{
    cin>>n;
    long long ans = 0, wn;
    lim = (n + 2) / 2;
    if (n & 1) {ans += (n + 1) / 2; wn = n - 1;}
    else {wn = n;}
    wn /= 2;
    ans += 1LL * (wn + 1) * wn;
    cout<<ans<<endl;
    dfs(0, 1, 0, 0);
    return 0;
}