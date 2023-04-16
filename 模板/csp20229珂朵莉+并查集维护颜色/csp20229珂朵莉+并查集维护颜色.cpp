#include <bits/stdc++.h>
#define IT set<Node>::iterator
using namespace std;
const int N = 1e6 + 50;

int n, m, q, fa[N], col[N], id[N], idtot;
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
namespace Tree
{
    int t[N], mx[N];
    #define lc (u << 1)
    #define rc (u << 1 | 1)
    void pu(int u)
    {
        if (t[lc] >= t[rc]) {mx[u] = mx[lc]; t[u] = t[lc];}
        else {mx[u] = mx[rc]; t[u] = t[rc];}
    }
    void add(int u, int l, int r, int pos, int val)
    {
        if (l == r) {t[u] += val; mx[u] = (t[u] ? l : 0); return ;}
        int mid = l + r >> 1;
        if (pos <= mid) add(lc, l, mid, pos, val);
        else add(rc, mid + 1, r, pos, val);
        pu(u);
    }
    void add(int pos, int val)
    {
        if (pos) add(1, 1, m, pos, val);
    }
    int query(int u, int l, int r, int pos)
    {
        if (l == r) return t[u];
        int mid = l + r >> 1;
        if (pos <= mid) return query(lc, l, mid, pos);
        else return query(rc, mid + 1, r, pos);
    }
    int query(int pos) {return query(1, 1, m, pos);}
    int qmx() {return mx[1];}
}

struct Node
{
    int l, r;
    mutable int c;
    Node(int L, int R = -1, int C=0):l(L), r(R), c(C) {}
    bool operator <(const Node &t) const {return l < t.l;}
};
set <Node> s;
IT split(int pos)
{
    IT it = s.lower_bound(Node(pos));
    int flag = 0;
    if (it == s.end()) flag = 1;
    if (it != s.end() && it->l == pos) return it;
    --it;
    if (flag && pos > it->r) return s.end();
    int L = it->l, R = it->r, C = it->c;

    //Tree::add(col[find(itl->c)], -(itl->r - itl->l + 1));
    s.erase(it);

    //Tree::add(col[C], R - L + 1);
    s.insert(Node(L, pos - 1, C));
    return s.insert(Node(pos, R, C)).first;
}
void output(IT qu) {cout<<"("<< qu->l<< " "<<qu->r <<" "<< qu->c<<")  "; cout<< (qu == s.end()) <<endl;}
void pset() {for (IT it = s.begin(); it != s.end(); it++) cout<<"("<< it->l<< " "<<it->r <<" "<< it->c<<")  "; cout<<endl;}
void assign(int l, int r, int c)
{
    //cout<<"assign: "<<l<<" "<<r<<" "<<c<<endl;
    if (!s.empty())
    {
        IT itr = split(r + 1);
        IT itl = split(l);
        for (IT it = itl; it != itr; ++it)
        {
            //cout<< "erase: "<<it->l <<" "<< it->r<<endl;
            Tree::add(col[find(it->c)], -(it->r - it->l + 1));
        }
        s.erase(itl, itr);
    }
    s.insert(Node(l, r, c));
    Tree::add(col[find(c)], r - l + 1);
}

void hb(int u, int v)
{
    u = find(u); v = find(v);
    if (u != v) fa[u] = v;
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
        fa[i] = id[i] = col[i] = i;
    idtot = m;
    for (int op, x, y, c; q--;)
    {
        scanf("%d", &op);
        if (op == 1) //区间推平
        {
            scanf("%d%d%d", &x, &y, &c);
            assign(x, y, id[c]);
        }
        if (op == 2) //x的颜色改成y
        {
            scanf("%d%d", &x, &y);
            hb(id[x], id[y]);
            int siz = Tree::query(x);
            Tree::add(x, -siz);
            if (y) Tree::add(y, siz);
            id[x] = ++idtot;
            fa[idtot] = idtot;
            col[idtot] = x;
        }
        if (op == 3) //x和y颜色交换
        {
            scanf("%d%d", &x, &y);
            col[id[x]] = y;
            col[id[y]] = x;
            swap(id[x], id[y]);
            int siz1 = Tree::query(x);
            int siz2 = Tree::query(y);
            Tree::add(x, -siz1 + siz2);
            Tree::add(y, -siz2 + siz1);
        }
        if (op == 4) //x出现了多少次
        {
            scanf("%d", &x);
            printf("%d\n", Tree::query(x));
        }
        if (op == 5) //出现次数最多的颜色
            printf("%d\n", Tree::qmx());
    }
    return 0;
}
/*
10 2 15
1 2 4 1
1 4 7 2
1 3 4 1
1 7 9 1
3 1 2
2 1 2
2 2 0
5
*/