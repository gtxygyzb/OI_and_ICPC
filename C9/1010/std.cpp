#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e12;
const int N = 1e5 + 50;
int a[N], b[N], t1[N], t2[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll ans = inf;
        int n, s, t, h;
        scanf("%d%d%d%d", &n, &s, &t, &h);

        for (int i = 1; i < n; i++)
            scanf("%d", a+i);
        for (int i = 1; i < n; i++)
            scanf("%d", b+i);
        
        for (int v1 = 1; v1 <= h; v1++)
        {
            for (int i = 1; i < n; i++)
                t1[i] = a[i];
            t1[n] = v1;
            sort(t1 + 1, t1 + n + 1);
            ll s1 = 0;
            for (int i = s + 1; i <= n - t; i++)
            {
                s1 += t1[i];
                //cout<<t1[i]<<" ";
            }

            for (int v2 = 1; v2 <= h; v2++)
            {
                for (int i = 1; i < n; i++)
                    t2[i] = b[i];
                t2[n] = v2;
                sort(t2 + 1, t2 + n + 1);
                ll s2 = 0;
                for (int i = s + 1; i <= n - t; i++)
                    s2 += t2[i];
                if (s1 > s2)
                {
                    if (v1 - v2 < ans)
                    {
                        //cout<<v1<<" "<<v2<<endl;
                        ans = 1LL*(v1 - v2);
                    }
                }
            }
        }
        if (ans == inf) puts("IMPOSSIBLE");
        else printf("%lld\n", ans);
    }
    return 0;
}