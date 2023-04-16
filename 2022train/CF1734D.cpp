#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
typedef long long ll;
int n, k, a[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);
        ll cur = a[k];
        int l = k, r = k, ans = 0;
        while (1)
        {
            ll pos, mx, flag = 0;
            int sl = l, sr = r;

            pos = r, mx = cur;
            //cout<<"l, r: "<<l<<" "<<r<<endl;
            while (r != n && cur + a[r + 1] >= 0)
            {
                cur += a[++r];
                if (cur > mx) mx = cur, pos = r;
            }
            if (r == n) {ans = 1; break;}
            r = pos; cur = mx;
            //cout<<"l, r: "<<l<<" "<<r<<endl;
            pos = l, mx = cur;
            while (l != 1 && cur + a[l - 1] >= 0)
            {
                cur += a[--l];
                if (cur > mx) mx = cur, pos = l;
            }
            if (l == 1) {ans = 1; break;}
            l = pos; cur = mx;
            if (sl == l && sr == r) break;
        }

        puts(ans ? "YES" : "NO");
    }
    return 0;
}
/*
1
7 4
-1 -2 -4 6 -2 -4 -1
*/