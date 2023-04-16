#include <bits/stdc++.h>
using namespace std;
const int N = 250, inf = 0x3f3f3f3f;
int a[N], n, k, ans = -inf;
int work(int l, int r)
{
    int ret = 0;
    vector <int> in, out;
    for (int i = l; i <= r; i++) in.push_back(a[i]), ret += a[i];
    for (int i = 1; i < l; i++) out.push_back(a[i]);
    for (int i = r + 1; i <= n; i++) out.push_back(a[i]);
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());
    reverse(out.begin(), out.end());
    for (int i = 0; i < min(k, (int) min(in.size(), out.size())); i++)
        if (in[i] < out[i]) ret += out[i] - in[i];
    return ret;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for (int l = 1; l <= n; l++)
        for (int r = l; r <= n; r++)
            ans = max(ans, work(l, r));
    printf("%d\n", ans);
    return 0;
}