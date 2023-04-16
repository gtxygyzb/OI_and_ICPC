#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
int n, s, t;

int etop, head[N], f[N], p[N], mx[N];
struct Edge
{
    int v, nxt;
}e[N<<1];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt= head[u];
    head[u] = etop;
}

void fp(int u, int fa)
{
    f[u] = fa;
    for (int i = head[u]; i; i = e[i].nxt)
        if (e[i].v != fa)
            fp(e[i].v, u);
}
void work(int u)
{
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == f[u] || p[v]) continue;
        work(v);
        mx[u] = max(mx[u], mx[v] + 1);
    }
}
int a[N], top, ans = -N;
int m1[N], m2[N];
multiset <int> q, q2;
int main()
{
    scanf("%d%d%d", &n, &s, &t);
    for (int u, v, i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    fp(s, 0);
    for (int x = t; x; x = f[x])
    {
        p[x] = 1;
        a[++top] = x;
    }
    for (int x = t; x; x = f[x])
        work(x);
    reverse(a + 1, a + top + 1); //从s到t
    for (int i = 1; i <= top; i++) // 第一个人能走的最长距离
    {
        int x = a[i];
        m1[x] = mx[x] + i - 1;
    }
    int b = 0;
    for (int i = top; i >= 1; i--) // 第二个人能走的
    {
        int x = a[i];
        m2[x] = mx[x] + b;
        q.insert(-m2[x]);
        ++b;
    }
    for (int i = 1; i <= (top + 1) / 2; i++)
    {
        int x = a[i];
        multiset <int>::iterator pos = q.find(-m2[x]); 
        q.erase(pos);
        int l1 = m1[x], l2 =  -(*q.begin());
        cout<<"x:"<<x<<" "<<l1<<" "<<l2<<endl;
        ans = max(ans, l1 - l2);
    }
    int tmp = q.count(*q.begin()), cur = (*q.begin());
    cout<<tmp<<" "<<cur<<endl;
    for (int i = (top + 1) / 2 + 1; i < top; i++)
    {
        int x = a[i];
        multiset <int>::iterator pos = q.find(-m2[x]); 
        q.erase(pos);
        int u = (*q.begin());
        cout<<q.count(u)<<" "<<u<<endl;
        if (q.count(u) != tmp || cur != u) break;
        int l1 = m1[x], l2 =  -u;
        cout<<"rex:"<<x<<" "<<l1<<" "<<l2<<endl;
        ans = max(ans, l1 - l2);
    }
    cout<<ans<<endl;
    return 0;
}