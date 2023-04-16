#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
vector <int> vec[N];

int n, m, a[N], b[N], st[N], ed[N];

int cnt, pri[N], vis[N], low[N];
void init()
{
    for (int i = 2; i <= N - 50; i++)
    {
        if (!vis[i]) {pri[++cnt] = i; low[i] = i;}
        for (int j = 1; j <= cnt && i * pri[j] <= N - 50; j++)
        {
            vis[i * pri[j]] = 1;
            low[i * pri[j]] = pri[j];
            if (i % pri[j] == 0) break;
        }
    }
}

bool check(int u, int l, int r) //vec[u]里是否存在l,r里的数
{
    if (!vec[u].size() || vec[u].back() < l) return 0;
    int x = *lower_bound(vec[u].begin(), vec[u].end(), l);
    return x <= r;

}
int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a+i);
            vec[i].clear();
        }
        for (int i = 1; i < n; i++)
            scanf("%d", b+i);
        for (int i = 1; i <= n; i++)
        {
            int x = a[i];
            while (x > 1)
            {
                int div = low[x];
                while (low[x] == div)
                    x /= div;
                vec[div].push_back(i);
                //cout<<div<<" : "<<i<<endl;
            }
        }
        for (int i = n; i; i--)
        {
            ed[i] = i;
            //cout<<i<<endl;
            while (ed[i] < n && check(b[ed[i]], i, ed[i]))
                ed[i] = ed[ed[i] + 1];
        }

        for (int i = 1; i <= n; i++)
        {
            if (i > 1 && ed[i - 1] >= i)
            {
                if (check(b[i - 1], i, ed[i]))
                    st[i] = st[i - 1], ed[i] = ed[i - 1];
                else
                    st[i] = i;
            }
            else
            {
                st[i] = i;
                while (1)
                {
                    bool flag = 0;
                    while (ed[i] < n && check(b[ed[i]], st[i], ed[i]))
                        flag = 1, ed[i] = ed[ed[i] + 1];
                    
                    while (st[i] > 1 && check(b[st[i]- 1], st[i], ed[i]))
                        flag = 1, st[i] = st[st[i] - 1];
                    if (!flag) break;
                }
            }
            //cout<<st[i]<<" " <<ed[i]<<endl;
        }
        for (int x, y; m--;)
        {
            scanf("%d%d", &x, &y);
            puts( (st[x] <= y && y <= ed[x]) ? "Yes" : "No");
        }
    }
    return 0;
}