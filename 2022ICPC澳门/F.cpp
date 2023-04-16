#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 50;

struct Data
{
    ll w, pos;
    bool operator <(const Data &t) const {return w < t.w;}
};
priority_queue <Data> q;
ll n, a[N], sum, ad, ans[N];
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if (sum > n * (n - 2)) return 0 * puts("Recurrent");
    for (int i = 1; i <= n; i++)
        q.push(Data{a[i], i});
    
    while (!q.empty())
    {
        Data u = q.top();
        if (u.w < 0) return 0 * puts("Recurrent");
        if (u.w + ad < n - 1)
        {
            while (!q.empty())
            {
                Data i = q.top(); q.pop();
                ans[i.pos] = i.w + ad;
            }
            break;
        }
        q.pop();
        ad += 1;
        u.w -= n;
        q.push(u);
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", ans[i], i == n ? '\n' : ' ');
    return 0;
}