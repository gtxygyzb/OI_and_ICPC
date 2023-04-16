#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 50;
struct Data
{
    int val, pos;
    void input(int i)
    {
        scanf("%d", &val);
        pos = i;
    }
    bool operator <(const Data &t) const
    {
        return val < t.val;
    }
}a[N];

int ch[N * 32][2], pos[N * 32], top = 1; //子树最大值的位置
int n, k, p[N], f[N];
int find(int i) //找a[i] ^ a[x] >= k 的, 且f[x]最大的x
{
    int u = 1, x = 0;
    for (int j = 30; j >= 0 && u; j--)
    {
        int c = (a[i].val >> j) & 1;
        int r = c ^ 1;
        if ((k >> j) & 1) //k的第j位为1，为了比他大，只能找1
            u = ch[u][r];
        else
        {
            if (f[x] < f[pos[ch[u][r]]]) //走一次1，直接取子树最大
                x = pos[ch[u][r]];
            u = ch[u][c]; //走0
        }
        if (j == 0 && f[x] < f[pos[u]]) //走一次1，直接取子树最大
            x = pos[u];
    }
    return x;
}
void insert(int i)
{
    int u = 1;
    for (int j = 30; j >= 0; j--)
    {
        int c = (a[i].val >> j) & 1;
        if (!ch[u][c]) ch[u][c] = ++top;
        u = ch[u][c];
        if (f[pos[u]] < f[i])
            pos[u] = i;
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        a[i].input(i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int pre = find(i);
        p[i] = pre;
        //cout<<"i: "<<i<<" "<<pre<<endl;
        f[i] = f[pre] + 1;
        insert(i);
    }
    int ans = 1;
    for (int i = 2; i <= n; i++)
        if (f[ans] < f[i]) ans = i;
    if (f[ans] < 2) return 0 * puts("-1");
    printf("%d\n", f[ans]);
    for (int i = ans; i; i = p[i])
        printf("%d ", a[i].pos);
    return 0;
}