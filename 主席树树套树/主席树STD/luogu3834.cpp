#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;

namespace Tree
{
    const int M = N * 40;
    int lc[M], rc[M], val[M], top;
    void init()
    {
        for (int i = 1; i <= top; i++)
            lc[i] = rc[i] = val[i] = 0;
        top = 0;
    }
    void add(int &u, int pre, int l, int r, int pos)
    {
        u = ++top; //新建结点
        lc[u] = lc[pre]; rc[u] = rc[pre]; //左右节点继承pre
        val[u] = val[pre] + 1; //权值加一
        if (l == r) return ; //最后一层返回
        int mid = l + r >> 1;
        if (pos <= mid) add(lc[u], lc[pre], l, mid, pos); //往左
        else add(rc[u], rc[pre], mid + 1, r, pos); //往右
    }
    int query(int u, int pre, int l, int r, int k)
    {
        if (l == r) return l;
        int sum = val[lc[u]] - val[lc[pre]]; // 左节点权值数量
        int mid = l + r >> 1;
        if (k <= sum) return query(lc[u], lc[pre], l, mid, k); //往左递归
        else return query(rc[u], rc[pre], mid + 1, r, k - sum); //减掉左节点往右递归
    }
}

int rt[N], n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for (int val, i = 1; i <= n; i++)
    {
        scanf("%d", &val);
        Tree::add(rt[i], rt[i - 1], -1e9, 1e9, val);
    }
    for (int l, r, k; m--;)
    {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", Tree::query(rt[r], rt[l-1], -1e9, 1e9, k));
    }
	return 0;
}
