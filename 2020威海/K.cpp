#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++)
    {
        int x, ans;
        scanf("%d", &x);
        if (x == 6) ans = -1;
        else if (x & 1) ans = 1;
        else if (x % 4 == 0) ans = 2;
        else if (x % 6 == 0) ans = 2;
        else
        {
            int a = x / 3;
            if (__gcd(a - 1, a + 2) == 1) ans = 3;
            else ans = 4;
        }
        printf("Case #%d: %d\n", cs, ans);
    }
    return 0;
}
/*
1
1
a 1
*/