#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
char ch[N];
int n;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", ch);
        n = strlen(ch);
        int sam = 1;
        for (int i = 1; i < n; i++)
            if (ch[i] != ch[i - 1]) sam = 0;
        if (n == 1) puts("1 2");
        if (n == 2)
        {
            if (sam == 1) puts("2 8");
            else puts("2 6");
        }
        if (n >= 3)
        {
            if (sam == 1) puts("2 4");
            else puts("2 2");
        }
    }
    return 0;
}
/*
2
a
ab
*/