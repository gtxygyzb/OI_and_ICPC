#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 50;

int n, rt[N], len[N];

namespace PST // Persistable Segment Tree
{
    int top;
    struct Tree
    {
        int l, r, val;
    }t[N * 30]; //nlogn space
    void init() {top = 0;}
    void add(int &u, int pre, int l, int r, int pos, int val)
    {
        t[u = ++top] = t[pre];
        if (l == r) {t[u].val = val; return ;}
        int mid = l + r >> 1;
        if (pos <= mid) add(t[u].l, t[pre].l, l, mid, pos, val);
        else add(t[u].r, t[pre].r, mid + 1, r, pos, val);
    }
    int query(int u, int l, int r, int pos)
    {
        if (l == r) return t[u].val;
        int mid = l + r >> 1;
        if (pos <= mid) return query(t[u].l, l, mid, pos);
        return query(t[u].r, mid + 1, r, pos);
    }
}

char read()
{
    char ch;
    for (ch = getchar(); (ch < 'a' || ch > 'z') && (ch <'A' || ch > 'Z'); )
        ch = getchar();
    return ch;
}
int main()
{
    PST::init();
    char ch;
    scanf("%d", &n);
    for (int i = 1, x, cnt = 0; i <= n; i++)
    {
        ch = read();
        if (ch == 'T')
        {
            ch = read();
            ++cnt; len[cnt] = len[cnt - 1] + 1;
            PST::add(rt[cnt], rt[cnt - 1], 1, n, len[cnt], ch);
        }
        if (ch == 'U')
        {
            scanf("%d", &x);
            ++cnt;
            rt[cnt] = rt[cnt - x - 1];
            len[cnt] = len[cnt - x - 1];
        }
        if (ch == 'Q')
        {
            scanf("%d", &x);
            printf("%c\n", (char)(PST::query(rt[cnt], 1, n, x)));
        }
    }
    return 0;
}