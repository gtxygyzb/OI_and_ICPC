#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, k, a[N];
int main()
{
    scanf("%d%d", &n, &k);
    if (k == 0 || k > n) return 0 * puts("-1");
    for (int i = 1; i <= n; i++)
        a[i] = i;
    int l;
    if (k & 1) {l = 2; --k;}
    else l = 1;
    for (; l <= n && k >= 2; l += 2) 
    {
        swap(a[l], a[l + 1]);
        k -= 2;
    }
    if (k == 1) swap(a[l], a[max(l - 2, 1)]);
    for (int i = 1; i <= n; i++)
    {
        printf("%d", a[i]);
        if (i != n) putchar(' ');
    }
    return 0;
}