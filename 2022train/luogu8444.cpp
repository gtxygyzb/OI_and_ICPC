#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, a[N], w;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    scanf("%d", &w);
    sort(a + 1, a + n + 1);
    if (a[1] > w) return 0 * puts("0");
    int pos = upper_bound(a + 1, a + n + 1, w) - a - 1;
    int val = a[pos], ans = 0;
    //cout<<val<<endl;
    for (int i = 1; i <= n; i++)
    {
        if (val >= a[i]) val -= a[i], ++ans;
        else return 0 * printf("%d\n", ans);
        //cout<<val<<" "<<a[i]<<endl;
    }
}