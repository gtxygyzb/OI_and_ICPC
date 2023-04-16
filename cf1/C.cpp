#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, x;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%lld%lld", &k, &x);
        if ( ((k + 1) * k / 2 + k * (k - 1) / 2) <= x )
        {
            printf("%lld\n", 2 * k - 1);
            continue;
        }
        if ((k + 1) * k / 2 >= x)
        {
            ll l = 1, r = k;
            while (l < r)
            {
                ll mid = l + r >> 1;
                if ((mid + 1) * mid >= x + x) r = mid;
                else l = mid + 1;
            }
            printf("%lld\n", l);
        }
        else
        {
            x -= (k + 1) * k / 2;
            ll l = k - 1, r = 1, ans;
            //cout<<l<<" "<<r<<endl;
            while (r <= l)
            {
                ll mid = l + r >> 1;
                //out<<"mid:"<<l<<" "<<r<<" "<<mid<<" "<<(k - 1 + mid) * (k - mid)<<endl;
                if ((k - 1 + mid) * (k - mid) >= x + x) {ans = r; r = mid + 1;}
                else l = mid - 1;
            }
            if ((k - 1 + l) * (k - l) >= x + x) ans = l;
            printf("%lld\n", k - ans + k);
        }
    }
    return 0;
}