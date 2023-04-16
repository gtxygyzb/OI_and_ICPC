#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
char s[N];
int ao, li;
int main()
{
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            if (s[i] == '1') ++ao;
            else return 0 * puts("-1");
            continue;
        }
        if (s[i] == '1' && s[i + 1] == '1')
            ++ao;
        else if (s[i] == '1' && s[i + 1] == '0')
            {++li; ++i;}
        else if (s[i] == '0' && s[i + 1] == '1')
            {++li; ++i;}
        else return 0 * puts("-1");
    }
    printf("%d\n", max(ao, li));
    return 0;
}