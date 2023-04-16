#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h, m, a, ans;
int main()
{
    cin>>h>>m>>a;
    ll vh = 1, vm = h;
    ll pos = 0, mul = h * m; ++ans;
    for (ll i = 1; i < mul; i++)
    {
        pos += h - 1;
        pos %= mul;
        if (pos <= a || pos >= mul - a)
        {
            ++ans;
            cout<<pos<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}