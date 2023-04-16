#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<bitset>
#include<stack>
#include<string>
#include<queue>
#include<cmath>
#include<numeric>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 10;
const int mod = 998244353;

int n;
int a[MAXN];
int num[MAXN];

int c[MAXN];

int lbt(int x)
{
    return x & -x;
}

int find(int p)
{
    int ans = 0;
    while (p >= 1)
    {
        ans += c[p];
        p -= lbt(p);
    }
    return ans;
}

void add(int p, int x)
{
    while (p <= n)
    {
        c[p] += x;
        p += lbt(p);
    }
}
int pos[MAXN];
int cnt[MAXN];


void solve()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        pos[i] = 0;
        c[i] = 0;
        cnt[i] = 0;
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        int id = find(a[i]);
        num[i] = (int)s.size() - id;
        if (s.find(a[i])==s.end()) add(a[i], 1);
        s.insert(a[i]);
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) pos[a[i]] = i;
    }
    int mx = a[1], mxn = 1;
    ll ans = 0;
    printf("0");
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > mx)
        {
            int tp = 1;
            if (pos[mx] < i && pos[mx] != 0)
            {
                ans += 1 + i - pos[mx] + 1;
            }
            else
            {
                ans += 1 + mxn;
            }

            printf(" %lld", ans);
            mx = a[i];
            mxn = 1;
           
        }
        else if (a[i] == mx)
        {
            mxn++;
            printf(" %lld", ans);
        }
        else
        {
            ans += num[i];
            printf(" %lld", ans);
        }
    }
    puts("");
}


void init()
{


}

int main()
{
    init();
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}