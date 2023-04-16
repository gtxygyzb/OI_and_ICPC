#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 50;
string s[N];
bool cmp(string s1, string s2)
{
    return s1 + s2 < s2 + s1;
}
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>s[i];
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        cout<<s[i];
    return 0;
}