#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50, M = 30;
int n, b[N], c[N], bin[M+5];
int f[M];

int check(int k, int x) //第k位填st
{
    for (int i = 2; i <= n; i++)
    {
        if (x == 0)
        {
            if (c[i] & bin[k])
                return 0;
            if (b[i] & bin[k])
                x = 1;
        }
        else
        {
            if ((b[i] & bin[k]) == 0)
                return 0;
            if ((c[i] & bin[k]) == 0)
                x = 0;
        }
    }
    return 1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &c[i]);
        c[i] -= b[i];
    }
    
    bin[0] = 1;
    for (int i = 1; i < M; i++)
        bin[i] = bin[i-1]<<1;
    int ans = 1;
    for (int i = 0; i < M; i++)
        ans *= (check(i, 1) + check(i, 0));
    printf("%d\n", ans);
    return 0;
}