#include <bits/stdc++.h>
using namespace std;
const int N = 45;

void chr(int x)
{
    printf("%d", x % 10);
    x /= 10;
    if (x == 0) putchar('w');
    else if (x == 1) putchar('b');
    else if (x == 2) putchar('s');
    else putchar('z');
}
int rk(char c) {return c == 'w' ? 0 : (c == 'b' ? 10 : (c == 's' ? 20 : 30));}
void output(int a[])
{
    for (int i = 1; i <= 37; i++)
        for (int j = 1; j <= a[i]; j++)
            cout<<i<<" ";
    puts("");
}
int check(int *c)
{
    int a[N], tot = 0;
    memcpy(a, c, sizeof(a));
    for (int i = 31; i <= 37; i++)
    {
        if (a[i] >= 3) ++tot;
        a[i] %= 3;
        if (a[i] != 0) return 0;
    }
    for (int i = 1; i <= 29; i++)
    {
        if (!a[i]) continue;
        if (a[i] >= 3) a[i] -= 3, ++tot;
        if (!a[i]) continue;
        if (i % 10 >= 8) return 0; //剩下8和9，凑不成顺子
        int del = min(a[i + 1], min(a[i + 2], a[i]));
        a[i] -= del; a[i + 1] -= del; a[i + 2] -= del;
        tot += del;
        if (a[i]) return 0;
    }
    return tot == 4;
}

int dfs(int a[])
{
    int ret = 0;
    for (int i = 1; i <= 37 && !ret; i++)
        if (a[i] >= 2)
        {
            a[i] -= 2;
            ret |= check(a);
            a[i] += 2;
        }
    return ret;
}

int a[N], ans;
char ch[N];
vector <int> vec[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", ch + 1);
        memset(a, 0, sizeof(a));
        ans = 0;
        for (int pos, i = 1; i <= 28; i += 2)
        {
            pos = ch[i] - '0' + rk(ch[i + 1]);
            ++a[pos];
        }
        if (dfs(a)) puts("Tsumo!");
        else
        {
            for (int i = 1; i <= 37; i++)
            {
                vec[i].clear();
                if (a[i])
                {
                    --a[i];
                    int p = 0;
                    for (int j = 1; j <= 37; j++)
                    {
                        if (i == j || j % 10 == 0) continue;
                        ++a[j];
                        if (dfs(a))
                        {
                            if (!p) p = 1, ++ans;
                            vec[i].push_back(j);
                        }
                        --a[j];
                    }
                    ++a[i];
                }
            }
            printf("%d\n", ans);
            for (int i = 1; i <= 37; i++)
                if (vec[i].size())
                {
                    chr(i); putchar(' ');
                    for (int j = 0; j < vec[i].size(); j++)
                        chr(vec[i][j]);
                    puts("");
                }
        }
    }
    return 0;
}
/*
5
1w2w3w4b5b6b7s8s9s1b1b1z2z6z
1w2w3w4b5b6b7s8s9s1b1b2z2z6z
1w2w3w4b5b6b7s8s9s1b1b2z2z2z
1b2b3b4b5b6b2s4s5s5s5s6s7s8s
1b1b1b2b3b4b5b6b7b8b9b9b9b1s

1
1w2w3w4b5b6b7s8s9s1b1b2z2z2z
*/