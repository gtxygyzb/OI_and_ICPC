#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if ((x + y) & 1) puts("-1 -1");
        else
        {
            if ((x & 1) == 0 && (y & 1) == 0)
                printf("%d %d\n", x / 2, y / 2);
            else if (x < y)
                printf("%d %d\n", x, (y - x) / 2);
            else printf("%d %d\n", (x - y) / 2, y);
        }
    }
    return 0;
}