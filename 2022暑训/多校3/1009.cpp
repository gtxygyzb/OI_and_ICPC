#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 50;
int n, k;
struct Data
{
    int l, r;
    void input() {scanf("%d%d", &l, &r);}
}a[N];

bool cmp(Data x, Data y)
{
    return x.r == y.r ? x.l < y.l : x.r < y.r;
}

struct Vis
{
    int l, r, id;
    Vis (int _l, int _r, int _id) {l = _l; r = _r; id = _id;}
    bool operator <(const Vis &t) const {return l == t.l ? r > t.r : l > t.l;}
};


int vis[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        priority_queue <Vis> q;
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            a[i].input();
        }
        sort(a + 1, a + n + 1, cmp);

        for (int i = 1; i <= n; i++)
            q.push(Vis(a[i].l, a[i].r, i));

        int ed = 0, sam = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i]) continue;
            if (ed != 0 && a[i].r != ed && sam) //右端点不同了
            {
                while (!q.empty() && sam < k)
                {
                    Vis u = q.top(); q.pop();
                    while (vis[u.id] && !q.empty())
                    {
                        u = q.top(); q.pop();
                    }
                    if (u.l > ed || vis[u.id])
                    {
                        if (vis[u.id] == 0) q.push(u);
                        break; //后面所有的l都没有小于等于ed的了，直接++ans
                    }
                    else
                    {
                        vis[u.id] = 1;
                        ++sam;
                    }
                }
                sam = 0;
                ++ans;
            }

            ed = a[i].r;
            if (vis[i]) continue;

            vis[i] = 1;
            ++sam;
            if (sam == k) {sam = 0; ++ans;}
            
        }

        if (sam) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
/*
10 5
1 3
2 4

3 4
3 9

5 6
6 7

7 8
8 9

9 11
11 15
*/