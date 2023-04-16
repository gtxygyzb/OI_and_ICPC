#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int n, m;
ld ans;
int main()
{
    int id, T;
    scanf("%d%d", &id, &T);
    while (T--)
    {
        ans = 0;
        scanf("%d%d", &n, &m);
        printf("%d ", n * m - ((n + 1) / 2) * ((m + 1) / 2));
        if (n <= 2 && m <= 2) {puts("0"); continue;}
        for (int hi = 1, hj = n; hi <= hj; hi += 2, hj -= 2)
            for (int li = 1, lj = m; li <= lj; li += 2, lj -= 2)
            {
                int t1 = max(hi - 1, n - hi);
                int t2 = max(li - 1, m - li);
                int T1 = max(hj - 1, n - hj);
                int T2 = max(lj - 1, m - lj);
                ld ans1 = sqrt(t1 * t1 + t2 * t2);
                ld ans2 = sqrt(t1 * t1 + T2 * T2);
                ld ans3 = sqrt(T1 * T1 + t2 * t2);
                ld ans4 = sqrt(T1 * T1 + T2 * T2);
                bool f1 = hj - hi > 1, f2 = lj - li > 1;
                ans += ans1;
                if (f1) ans += ans3;
                if (f2) ans += ans2;
                if (f1 && f2) ans += ans4;
            }
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}