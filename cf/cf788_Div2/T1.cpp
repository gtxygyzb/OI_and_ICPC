#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int n, a[N], T;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a+i);
            if (a[i] < 0) ++cnt;
            a[i] = abs(a[i]);
        }
        for (int i = 1; i <= cnt; i++)
            a[i] = -a[i];
        int flag = 1;
        for (int i = 2; i <= n && flag; i++)
            if (a[i] < a[i - 1]) flag = 0;
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
/*
1
7
90 -80 -70 -60 50 -50 40
*/