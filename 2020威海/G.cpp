#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++)
    {
        ll c0, c1, c2, c3;
        scanf("%lld%lld%lld%lld", &c0, &c1, &c2, &c3);
        printf("Case #%d: ", cs);
        if (c0 + c1 + c2 + c3 <= 1) {puts("Horse"); continue;}

        int p1, p2;

        if (c0 == 0) p1 = 0;
        else if (c1 + c2 + c3 == 0) p1 = (c0 - 1) & 1;
        else p1 = c0 & 1;

        if (p1 == 0)
        {
            if (c1 % 3 == 0) p2 = 0;
            else if (c1 % 3 == 2) p2 = 1;
            else p2 = (c2 >= 1);
        }
        else
        {
            if (c1 % 3 == 0) p2 = 1;
            else if (c1 % 3 == 1) p2 = (c2 == 0);
            else p2 = (c2 >= 2);
        }

        //cout<<p1<<" "<<p2<<endl;
        puts(p2 ? "Rabbit" : "Horse");
    }
    return 0;
}/*
4
5 8 9 0
*/