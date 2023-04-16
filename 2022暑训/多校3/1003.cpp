#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int T;
    scanf("%d\n", &T);
    while (T--)
    {
        getline(cin, s);
        cout<<(char)(s[0] - 'a' + 'A');
        for (int siz = s.size(), i = 1; i <= siz; i++)
        {
            if (s[i - 1] == ' ') cout<<(char)(s[i] + -'a' + 'A');
        }
        cout<<'\n';
    }
    return 0;
}