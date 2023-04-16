#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 50;
int nxt[N];

int getnxt(string s)
{
    nxt[0] = -1;
    int i = 0, j = -1;
    int len = s.size();
    while (i < len)
    {
        if (j == -1 || s[i] == s[j])
        {
            ++i; ++j;
            nxt[i] = j;
        }
        else j = nxt[j];
    }
    return j;
}

string s, ans;
int n, len;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    ans = s;
    for (int i = 2; i <= n; i++)
    {
        cin >> s;
        len = min(ans.size(), s.size());
        string tmp = s + "!@#$%^&*" + ans.substr(ans.size() - len);
        int res = getnxt(tmp);
        ans += s.substr(res); //0 - res-1 相同
    }
    cout<<ans<<endl;
    return 0;
}
/*
5
sample please ease in out
*/