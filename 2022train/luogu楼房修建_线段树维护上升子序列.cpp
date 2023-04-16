#include <bits/stdc++.h>
#define lc (u << 1)
#define rc (u << 1 | 1)
using namespace std;
const int N = 1e6 + 50;
double mx[N];
int len[N], n, m;

int pu(int u, int l, int r, double k) //右区间[l, r]里大于k的，上升子序列长度
{
    if (l == r) return mx[u] > k;
    int mid = l + r >> 1;
    if (mx[lc] <= k) return pu(rc, mid + 1, r, k); //左区间没有比k大的，直接找右区间
    else return len[u] - len[lc] + pu(lc, l, mid, k); //右区间的答案为总的减左
}

void modify(int u, int l ,int r, int pos, double val)
{
    if (l == r) {mx[u] = val; len[u] = 1; return ;}
    int mid = l + r >> 1;
    if (pos <= mid) modify(lc, l, mid, pos, val);
    else modify(rc, mid + 1, r , pos, val);
    mx[u] = max(mx[lc], mx[rc]);
    len[u] = len[lc] + pu(rc, mid + 1, r, mx[lc]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int x, y; m--;)
    {
        scanf("%d%d", &x, &y);
        modify(1, 1, n, x, 1.0 * y / x);
        printf("%d\n", len[1]);
    }
    return 0;
}
/*
3 4
2 4
3 6
1 1000000000
1 1
*/