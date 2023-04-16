#include <bits/stdc++.h>
using namespace std;
const int N = 150;
int ans[N];
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        int xiao = a - 1, da = b + 1;
        int n2 = n / 2;
        /*if (n - b > n2 - 1 || xiao > n2 - 1)
        {
            puts("-1");
            continue;
        }*/
        ans[1] = a;
        ans[n] = b;
        int l = 1, r = n;
        for (int i = n; i >= b + 1; i--)
        {
            if (i == a) continue;
            ans[++l] = i;

        }
        
        for (int i = 1; i < a; i++)
        {
            if (i == b) continue;
            ans[--r] = i;
        }
        if (l > n2 || r <= n2)
        {
            puts("-1");
            continue;
        }
        
        for (int t = a + 1, i = l + 1; i < r; i++, t++)
            ans[i] = t;
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}