#include <bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", a+i);
            if (a[i] == 0) ++ans;
        }
        if (ans == 0) puts("Contemporary Xu Xiake");
        if (ans == 1) puts("Excellent Traveller");
        if (ans == 2) puts("Young Traveller");
        if (ans == 3) puts("Eye-opener");
        if (ans == 4) puts("Typically Otaku");
    }
    return 0;
}