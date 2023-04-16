#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 10;
const int mod = 998244353;

struct node
{
    int l, r;
}a[MAXN];

bool cmp(node a, node b)
{
    return a.r < b.r;
}
bool vis[MAXN];

struct node2
{
    int l, r, id;
    node2(int l, int r, int id) :l(l), r(r), id(id) {}
    bool operator<(const node2& y) const
    {
        if (y.l == l) return r > y.r;
        return l > y.l;
    }
};

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i].l, &a[i].r);
            vis[i] = 0;
        }
        sort(a + 1, a + n + 1, cmp);
        priority_queue<node2> pq;
        for (int i = 1; i <= n; i++)
        {
            pq.push(node2(a[i].l, a[i].r, i));
        }

        int sum = 1, ed = a[1].r, ans = 0;
        if (sum == k)
        {
            sum = 0;
            ans++;
        }
        vis[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            if (vis[i]) continue;
            if (a[i].r != ed && sum > 0)
            {
                while (sum < k && (!pq.empty()))
                {
                    node2 p = pq.top(); pq.pop();
                    if (vis[p.id]) continue;
                    if (p.l <= ed)
                    {
                        sum++;
                        vis[p.id] = 1;
                    }
                    else
                    {
                        pq.push(p);
                        break;
                    }
                }
                sum = 0;
                ans++;
            }
            ed = a[i].r;
            if (vis[i]) continue;
            vis[i] = 1;
            sum++;
            if (sum == k)
            {
                ans++;
                sum = 0;
            }
        }
        if (sum > 0) ans++;
        printf("%d\n", ans);
    }


    return 0;
}
