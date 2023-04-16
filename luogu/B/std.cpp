#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;

struct Data
{
    int opt, val;
    void input()
    {
        char c[10];
        scanf("%s%d", c, &val);
        opt = (c[0] == '*') ? 2 : 1;
    }
}a[N];

int n, id[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        a[i].input();
    for (int i = 1; i <= n; i++)
        id[i] = i;
    int ans = 0;
    do
    {
        int cur = 0;
        for (int i = 1; i <= n; i++)
            if (a[id[i]].opt == 2)
                cur *= a[id[i]].val;
            else 
                cur += a[id[i]].val;
        ans = max(ans, cur);
    }while(next_permutation(id + 1, id + n + 1));

    printf("%d\n", ans);
    /*do
    {
        int cur = 0;
        for (int i = 1; i <= n; i++)
            if (a[id[i]].opt == 2)
                cur *= a[id[i]].val;
            else 
                cur += a[id[i]].val;
        if (cur == ans)
        {
            for (int i = 1; i <= n; i++)
                printf("%c %d\n", a[id[i]].opt == 2 ? '*' : '+', a[id[i]].val);
            puts("--------");
        }
    }while(next_permutation(id + 1, id + n + 1));*/
    return 0;
}
/*
8
+ 70
+ 80
+ -80
+ -40
* 3
* 5
* -4
* -3
*/