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
typedef pair<ll, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 10;
const int mod = 998244353;

int a[MAXN];
int mx[MAXN][20];
int lg2[MAXN];

int find(int l, int r)
{
    int k = lg2[r - l + 1];
    return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}

void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        mx[i][0] = a[i];
    }
    if (k >= n)
    {
        sort(a + 1, a + n + 1);
        for (int i = n; i >= 2; i--)
        {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[1]);
        return;
    }
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
        }
    }
    int lb = 1;
    priority_queue<int> pq;
    queue<int> q;
    while (k)
    {
        int rb = min(lb + k, n);
        int mxx = find(lb, rb);
        int j = lb;
        while (a[j] != mxx)
        {
            pq.push(a[j]);
            j++;
        }
        q.push(a[j]);
        k -= (j - lb);
        lb = j + 1;
        if (lb > n) break;
    }
    vector<int> ans;
    while (!q.empty())
    {
        //printf("%d ", q.front());
        while (!pq.empty() && pq.top() > q.front())
        {
            //printf("%d ", pq.top());
            ans.push_back(pq.top());
            pq.pop();
        }
        ans.push_back(q.front());
        q.pop();
    }

    for (int i = lb; i <= n; i++)
    {
        while (!pq.empty() && pq.top() > a[i])
        {
            //printf("%d ", pq.top());
            ans.push_back(pq.top());
            pq.pop();
        }
       // printf("%d ", a[i]);
        ans.push_back(a[i]);
    }

    while (!pq.empty())
    {
        //printf("%d ", pq.top());
        ans.push_back(pq.top());
        pq.pop();
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[n - 1]);

   // puts("");
}


int main()
{
    lg2[1] = 0;
    for (int i = 2; i < MAXN; i++)
    {
        lg2[i] = lg2[i >> 1] + 1;
    }
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }

    return 0;
}
