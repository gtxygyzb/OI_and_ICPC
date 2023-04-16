#include <bits/stdc++.h>
using namespace std;
const int N = 450, M = 6, B = 20, inf = 0x3f3f3f3f;

void cmax(int &x, int y) {x = max(x, y);}
int read()
{
    int x = 0; char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) ;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x;
}
struct Data
{
    int op, t, m;
    void input()
    {
        char ch = getchar();
        for (; ch < 'A' || ch > 'Z'; ch = getchar()) ;
        if (ch == 'O') op = 1;
        if (ch == 'W') op = 2;
        if (ch == 'T') op = 3;
        if (ch == 'M') op = 4;
        if (ch == 'R') op = 5;
        t = read(); m = read();
    }
}a[N][M], fin[N];

int n, m, f[1 << B], pre[1 << B], id[1 << B], bin[B] = {1};

int trans(int u, int i)
{
    int ret = u;
    for (int j = 0; j < m; j++)
    {
        int p = j * 3;
        int op = (u >> p) & 1;
        if (fin[j].op >= 2) //不正确大类
        {
            if (op) continue ; // 只需要管不成立的
            if (a[i][j].op >= 2)
            {
                if (fin[j].op != a[i][j].op) return -1;
                ret |= bin[p]; //状态正确
            }
            if (a[i][j].t > fin[j].t || a[i][j].m > fin[j].m)
                return -1;
            if (a[i][j].t == fin[j].t)
                ret |= bin[p + 1];
            if (a[i][j].m == fin[j].m)
                 ret |= bin[p + 2];
        }
        else //正确大类，直接赋值1，因为a[i][j].op只可能为1
        {
            ret |= bin[p];
            if (a[i][j].t == fin[j].t)
                ret |= bin[p + 1];
            if (a[i][j].m == fin[j].m)
                ret |= bin[p + 2];
        }
    }
    return ret;
}
int ans[N], top;
int main()
{
    for (int i = 1; i < 20; i++)
        bin[i] = bin[i - 1] << 1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            a[i][j].input();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fin[j].op >= 2) continue;
            if (fin[j].op == 0)
                fin[j] = a[i][j];
            else // 1
            {
                if (a[i][j].op == 1)
                {
                    cmax(fin[j].t, a[i][j].t);
                    cmax(fin[j].m, a[i][j].m);
                }
                else
                {
                    fin[j].op = a[i][j].op;
                    cmax(fin[j].t, a[i][j].t);
                    cmax(fin[j].m, a[i][j].m);
                }
            }
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int u = 0; u < bin[3 * m]; u++)
    {
        if (f[u] == inf) continue;
        for (int i = 1; i <= n; i++)
        {
            int v = trans(u, i);
            if (v == -1) continue;
            if (f[v] > f[u] + 1)
            {
                f[v] = f[u] + 1;
                
                pre[v] = u;
                id[v] = i;
            }
        }
    }
    int M = bin[3 * m] - 1;
    printf("%d\n", f[M]);
    for (int u = M; u; u = pre[u])
        ans[++top] = id[u];
    for (int i = top; i >= 1; i--)
        printf("%d ", ans[i]);
    return 0;
}
/*
2 3
OK,1/1 OK,2/1 OK,2/2
WA,1/1 OK,1/1 TL,1000/1
*/