#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50, P = 998244353;

int n, t[2][2][N], top[2][2];

bool cmp(int x, int y)
{
    return x > y;
}

void add(int &x, int y)
{
    x += y;
    if (x >= P) x -= P;
    if (x < 0) x += P;
}
void mul(int &x, int y)
{
    x = ((1LL * x * y) % P + P) % P;
}
int main()
{
    scanf("%d", &n);
    char c[10];
    for (int val, i = 1; i <= n; i++)
    {
        scanf("%s%d", c, &val);
        int x = c[0] == '*', y = val > 0; //0 + 1 * 大于0为1
        t[x][y][++top[x][y]] = val;
    }
    int ans = 0;
    sort(t[1][0] + 1, t[1][0] + top[1][0] + 1, cmp);
    if (top[1][0] & 1) // 奇数个负乘，加负数，乘一个，加正数，总乘
    {
        for (int i = 1; i <= top[0][0]; i++)
            add(ans, t[0][0][i]);
        mul(ans, t[1][0][1]);
        for (int i = 1; i <= top[0][1]; i++)
            add(ans, t[0][1][i]);
    }
    else 
    {
        if (top[1][0] == 0) //没有负乘，加正数，乘，加负数
        {
            for (int i = 1; i <= top[0][1]; i++)
                add(ans, t[0][1][i]);
            for (int i = 1; i <= top[1][1]; i++)
                mul(ans, t[1][1][i]);
            for (int i = 1; i <= top[0][0]; i++)
                add(ans, t[0][0][i]);
            printf("%d\n", ans);
            return 0;
        }
        //偶数个负乘，加正数，乘负，加负数，总乘
        for (int i = 1; i <= top[0][1]; i++)
            add(ans, t[0][1][i]);
        mul(ans, t[1][0][1]);
        for (int i = 1; i <= top[0][0]; i++)
            add(ans, t[0][0][i]);
    }

    for (int i = 2; i <= top[1][0]; i++)
        mul(ans, t[1][0][i]);
    for (int i = 1; i <= top[1][1]; i++)
        mul(ans, t[1][1][i]);
    printf("%d\n", ans);
    return 0;
}