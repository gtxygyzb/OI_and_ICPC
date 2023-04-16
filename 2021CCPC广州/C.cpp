#include <bits/stdc++.h>
using namespace std;
#define mid (l + r >> 1)
typedef long long ll;
const int N = 2e6 + 50;

#define gc()(is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++)
const int Q = (1<<24)+1;
char in[Q],*is=in,*it=in,c;
void read(long long &n){
  for(n=0;(c=gc())<'0'||c>'9';);
  for(;c<='9'&&c>='0';c=gc())n=n*10+c-48;
}

ll n, m, a[N], del[N], ans, b[N];
int pos = 1;

bool check(ll lim)
{
    for (int i = pos; i < pos + m; i++)
        b[i] = del[i];
    b[pos + m] = 0;
    for (int i = pos; i < pos + m; i++)
        if (b[i] > lim)
        {
            ll ad = b[i] - lim;
            if (ad < 0) continue;
            b[i] = lim;
            if (ad > del[i] - 1)return 0;
            b[i + 1] += ad;
        }
    if (b[pos + m] + b[pos] > lim) return 0;
    return 1;
}
int main()
{
    //freopen("C.in", "r", stdin);
    read(n); read(m);
    for (int i = 1; i <= m; i++)
        read(a[i]);
    a[m + 1] = a[1] + n;
    for (int i = 1; i <= m; i++)
        del[i] = a[i + 1] - a[i];

    del[0] = del[m];
    del[m + 1] = del[1];
    for (int i = 2; i <= m; i++)
    {
        del[i + m] = del[i]; 
        if (del[i] > del[pos]) pos = i;
        else if (del[i] == del[pos] && del[i - 1] < del[pos - 1])
            pos = i;
    }
    ll l = 1, r = 1e18;
    while (l < r)
    {
        if (check(mid)) {ans = mid; r = mid;}
        else l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
/*
28000000000000000 7
2000000000000000 7000000000000000 8000000000000000 13000000000000000 18000000000000000 22000000000000000 27000000000000000
*/