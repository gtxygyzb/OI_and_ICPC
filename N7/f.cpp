#include <bits/stdc++.h>
using namespace std;
#define SI set<int>::iterator

const int N = 3e5 + 50;

int l[N], r[N], lr[N], ans, path[N], siz;

set <int> s;

bool check(int x)
{
    if (s.empty()) return 1;
    SI i = s.lower_bound(l[x]);
	if(i != s.begin())
    {
		i--;
		if (lr[*i] >= r[x]) return 0;
		i++;
	}
    if (i == s.end() || *i > r[x]) return 1;
    return 0;
}
struct Tree
{
    struct Edge
    {
        int v, nxt;
    }e[N<<1];
    int etop, head[N], tim;
    void init() {etop = tim = 0, memset(head, 0, sizeof(head));}
    void add(int u, int v)
    {
        e[++etop].v = v;
        e[etop].nxt = head[u];
        head[u] = etop;
    }
    void adds(int u, int v)
    {
        add(u, v);
        add(v, u);
    }

    void dfs(int u, int fa)
    {
        l[u] = ++tim;
        for (int v, i = head[u]; i; i = e[i].nxt)
        {
            v = e[i].v;
            if (v == fa) continue;
            dfs(v, u);
        }
        r[u] = tim;
        lr[l[u]] = r[u];
    }

    void work(int u, int fa, int top)
    {
        vector <int> ins;  //加上链头被删除的节点
        while (!check(u))  //不合法的话删除链头
        {
            s.erase(l[path[top]]);
            ins.push_back(path[top]);
            ++top;
        }

        s.insert(l[u]); //加入当前点
        path[++siz] = u;
        ans = max(ans, (int)s.size());
        for (int v, i = head[u]; i; i = e[i].nxt)
        {
            v = e[i].v;
            if (v != fa) work(v, u, top);
        }

        s.erase(l[u]);
        --siz;
        for (int i = 0; i < ins.size(); i++)
            s.insert(l[ins[i]]);
    }
}t1, t2;

int n;
void init()
{
    t1.init();
    t2.init();
    ans = 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%d", &n);
        for (int u, v, i = 2; i <= n; i++)
        {
            scanf("%d%d", &u, &v);
            t1.adds(u, v);
        }
        for (int u, v, i = 2; i <= n; i++)
        {
            scanf("%d%d", &u, &v);
            t2.adds(u, v);
        }
        t2.dfs(1, 0);
        /*for (int i = 1; i <= n; i++)
            cout<<"l,r:"<<l[i]<<" "<<r[i]<<endl;*/
        t1.work(1, 0, 1);
        printf("%d\n", ans);
    }
    return 0;
}