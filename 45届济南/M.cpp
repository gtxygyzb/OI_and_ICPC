#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int tim = 2 * n / k;
    int ans = k * tim < 2 * n ? tim + 1 : tim;
    printf("%d\n", max(ans, 2));
    return 0;
}