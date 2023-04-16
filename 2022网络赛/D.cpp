#include <bits/stdc++.h>
using namespace std;

char s[10];
int a[10][10], S, W, ans;

int check(int iswin)
{
    // W = 0 表示使最终局面为平局，W = 1 表示使最终局面为-1胜利，W = 2 表示使最终局面为1胜利。
    int xwin = 0, owin = 0;
    if (a[1][1] == a[2][2] && a[2][2] == a[3][3])
    {
        if (a[1][1] == 1) ++owin;
        else if (a[1][1] == -1) ++xwin;
    }
    if (a[1][3] == a[2][2] && a[2][2] == a[3][1])
    {
        if (a[2][2] == 1) ++owin;
        else if (a[2][2] == -1) ++xwin;
    }

    for (int i = 1; i <= 3; i++)
    {
        if (a[1][i] == a[2][i] && a[2][i] == a[3][i])
            if (a[1][i] == 1) ++owin;
            else if (a[1][i] == -1) ++xwin;
        if (a[i][1] == a[i][2] && a[i][1] == a[i][3])
            if (a[i][1] == 1) ++owin;
            else if (a[i][1] == -1) ++xwin;
    }
    if (iswin)
    {
        if (xwin + owin > 0) return 1;
        return 0;
    }
    if (xwin == 0 && owin == 0 && W == 0) return 1;
    else if (xwin && owin == 0 && W == 1) return 1;
    else if (xwin == 0 && owin && W == 2) return 1;
    return 0;
}

void work(int ndx, int ndo, int cur)
{
    if (ndx == 0 && ndo == 0)
    {
        ans += check(0);
        return ;
    }
    if (check(1))
    {
        /*puts("------------");
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
                cout<<a[i][j];
            cout<<endl;
        }
        puts("----------------");*/
        return ;
    }
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (a[i][j] == 0)
            {
                a[i][j] = cur;
                work(ndx - (cur == -1), ndo - (cur == 1), cur == -1 ? 1 : -1);
                a[i][j] = 0;
            }
}
int main()
{
    //freopen("D.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        for (int i = 1; i <= 3; i++)
        {
            scanf("%s", s);
            for (int j = 0; j < 3; j++)
                a[i][j + 1] = (s[j] == 'X' ? -1 : (s[j] == 'O' ? 1 : 0));
        }
        scanf("%d%d", &S, &W);
        /*
        S = 1 表示-1先手，S = 2 表示1先手（棋盘为空时的先手），
        W = 0 表示使最终局面为平局，W = 1 表示使最终局面为-1胜利，W = 2 表示使最终局面为1胜利。
        */
        int ndx = 0, ndo = 0;
        if (S == 1) ndx = 5, ndo = 4;
        else ndx = 4, ndo = 5;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                if (a[i][j] == -1) --ndx;
                else if (a[i][j] == 1) --ndo;

        int fst;
        if (S == 1)
        {
            if (ndx == ndo) fst = 1;
            else fst = -1;
        }
        else
        {
            if (ndx == ndo) fst = -1;
            else fst = 1;
        }
        work(ndx, ndo, fst);
        printf("%d\n", ans);
    }
    return 0;
}
/*
3
XO_
__O
X__
1 1
X__
___
___
1 1
XO_
__O
X__
1 1
*/