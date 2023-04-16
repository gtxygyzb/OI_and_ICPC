#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int a, n, ta[10], tb[10];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        memset(ta, 0, sizeof(ta));
        memset(tb, 0, sizeof(tb));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a);
            ++ta[a];
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a);
            ++tb[a];
        }
        int flag = 0;
        for (int i = 1; i <= 6; i++)
            if (ta[i] > 1 || tb[i] > 1) flag = 1;
        puts(flag ? "Win!" : "Just a game of chance.");
    }
    return 0;
}
/*
3
5
4 6 4 1 2
3 6 6 2 3
6
1 2 3 4 5 6
6 5 4 3 2 1
5
4 6 4 1 2
3 6 6 2 3
*/