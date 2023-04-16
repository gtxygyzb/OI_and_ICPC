#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
char s[N];
int n;
int main()
{
    scanf("%s", s);
    n = strlen(s);
    int flag = 1;
    for (int i = 0; i < n - 1; i++)
        if (s[i] != '9') flag = 0;
    if (flag) printf("%s\n", s);
    else
    {
        for (int i = 1; i < n ; i++)
            printf("9");
        puts("");
    }
    return 0;
}