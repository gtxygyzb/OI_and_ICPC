#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e6 + 50;
int n, z[N], f[N], a[N], sz, sf;
char opt[10];
ll x[N], y[N], ans;
int main()
{
    //freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s%d", opt, a+i);
        if (opt[0] == '+') z[++sz] = a[i];
        else f[++sf] = a[i];
    }
    sort(z + 1, z + sz + 1);
    sort(f + 1, f + sf + 1);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        x[i] = sf - (lower_bound(f + 1, f + sf + 1, a[i]) - f - 1);
        y[i] = sz - (lower_bound(z + 1, z + sz + 1, a[i]) - z - 1);
    }
    reverse(x + 1, x + n + 1);
    reverse(y + 1, y + n + 1);
    ll px = 0;
    x[n + 1] = x[n]; y[n + 1] = 0;

    x[0] = x[1]; y[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        if (y[i] != y[i + 1])
        {
            ans += (x[i + 1] - px)  * y[i];
            px = x[i + 1];
        }
        //cout<<x[i]<<" "<<y[i]<<endl;
        //system("pause");
    }
    //cout<<ans<<endl;
    printf("%.10lf\n", 1.0 * ans / sf / sz);
    return 0;
}
/*
8
+ 34
+ 33
+ 26
- 34
- 38
+ 39
- 7
- 27

3
+ 2
- 3
- 1


6
+ 7
- 2
- 5
+ 4
- 2
+ 6
*/