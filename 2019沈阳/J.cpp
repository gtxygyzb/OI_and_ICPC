#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin>>T;
    for (int cs = 1; cs <= T; cs++)
    {
        int n; cin>>n;
        getline(cin, s);
        ll ans = 0;
        while (n--)
        {
            getline(cin, s);
            int len = s.size(), x = 1;
            double typ;
            if (s[0] == 'c') typ = 1;
            if (s[0] == 'b') typ = 1;
            if (s[0] == 'i') typ = 4;
            if (s[0] == 'f') typ = 4;
            if (s[0] == 'd') typ = 8;
            if (s[0] == 'l' && s[5] == 'l') typ = 8;
            if (s[0] == 'l' && s[5] == 'd') typ = 16;
            if (s[0] == '_') typ = 16;
            for (int i = 0; i < len; i++)
            {
                if (s[i] == '[')
                {
                    x = 0; ++i;
                    while (s[i] != ']')
                    {
                        x = x * 10 + s[i] - '0';
                        ++i;
                    }
                }
            }
            ans += x * typ;
        }
        cout<<"Case #"<<cs<<": "<<((ans + 1023) / 1024)<<endl;
    }
    return 0;
}