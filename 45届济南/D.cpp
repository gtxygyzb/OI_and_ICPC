#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;

ll ans;
int n;
struct Data
{
    int l, r;
    bool operator <(const Data &t) const
    {
        return r < t.r;
    }
    void input() {scanf("%d%d", &l, &r);}
}a[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        a[i].input();
    sort(a + 1, a + n + 1);
    int l, r;
    int pmx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].r != a[i - 1].r)
        {
            l = i;
        }
        if (a[i].r != a[i + 1].r)
        {
            r = i;
            int mx = 0;
            for (int j = l; j <= r; j++)
                mx = max(mx, a[j].l);
            if (mx <= pmx) mx = pmx;
            ans += 1LL * (r - l + 1) * mx;
            pmx = mx;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
6
5 5
4 5
2 3
1 2
2 2
1 3
*/ 