#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
int n, ans[N];
struct Data
{
    int l, r, id;
    bool operator <(const Data &t) const {return r == t.r ? l > t.l : r > t.r;}
}a[N];

bool cmp(Data t1, Data t2)
{
    return t1.l == t2.l ? t1.r < t2.r : t1.l < t2.l;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int b, i = 1; i <= n; i++)
        {
            scanf("%d", &b);
            a[i] = Data{i / (b + 1) + 1, (b == 0 ? n : i / b), i};
            //cout<<a[i].l<<" "<<a[i].r<<endl;
        }
        sort(a + 1, a + n + 1, cmp);
        //puts("paixuwanle");
        priority_queue <Data> q;
        for (int pos = 1, i = 1; i <= n; i++)
        {
            while (pos <= n && a[pos].l == i) q.push(a[pos++]);
            //cout<<q.top().l<<" "<<q.top().r<<" "<<q.top().id<<endl;
            ans[q.top().id] = i; q.pop();
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
/*
4
5
0 0 1 4 1
*/