#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
const ll inf = 1e18;

int n, tot, t[N];
void add(int x)
{
    ++tot;
    for (; x <= n; x += x & -x)
        ++t[x];
}
int query(int x)
{
    int ret = 0;
    for (; x; x -= x & -x)
        ret += t[x];
    return ret;
}
int pos(int x) {return x + tot - query(x);}
void init()
{
    tot = 0;
    for (int i = 1; i <= n; i++) t[i] = 0;
}

char a[N], b[N];
ll ans, cur;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%s%s", &n, a, b);
        init();
        set <int> s[26];
        for (int i = 0; i < n; i++)
            s[a[i] - 'a'].insert(i);
        ll ans = inf, cur = 0;
        for (int i = 0; i < n; i++)
        {
            int c = b[i] - 'a';
            for (int j = 0; j < c; j++) //直接选小的
                if (!s[j].empty())
                    ans = min(ans, cur + pos(*s[j].begin()) - i);
            
            if (!s[c].empty()) //选相等
            {
                int x = *s[c].begin();
                //cout<<i<<" "<<c<<" "<<pos(x)<<endl;
                if (pos(x) != i) {add(x); cur += pos(x) - i;}
                s[c].erase(s[c].begin());
            }
            else break; //当前位找不到相等
        }
        printf("%lld\n", ans == inf ? -1 : ans);
    }
    return 0;
}
/*
1
3
caa
aca
*/