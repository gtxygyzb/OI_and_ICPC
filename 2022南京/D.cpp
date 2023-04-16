#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, a[N], c[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a+i);
            c[i] = a[i];
        }
        
        for (int nn = 1; nn <= n; nn++)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
                a[i] = c[i];
            for (int i = 1; i <= nn; i++)
                for (int j = 1; j <= nn; j++)
                    if (a[i] < a[j])
                    {
                        swap(a[i], a[j]); ++cnt;
                    }
            printf("%d", cnt);
            if (nn == n) puts("");
            else printf(" ");
        }
    }
    return 0;
}
/*
1
10
4 1 4 2 7 1 4 5 7 4

*/