#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 50;
int n, a[N], id[N];

ll c[10];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);

        id[1] = 1;
        id[2] = 2;
        id[3] = 3;
        c[1] = a[1]; c[2] = a[2]; c[3] = a[3];

        for (int u, v, i = 4; i <= n; i++)
        {
            scanf("%d%d", &u, &v);
            if (id[u] > id[v]) swap(u, v);
            if (id[u] == 1 && id[v] == 2) id[i] = 3;
            if (id[u] == 1 && id[v] == 3) id[i] = 2;
            if (id[u] == 2 && id[v] == 3) id[i] = 1;
            c[id[i]] += a[i];
        }
        printf("%lld\n", max(c[1], max(c[2], c[3])));
    }
    return 0;
}
/*
3
4
3 3 2 2
1 2
4
2 5 5 2
2 3
5
3 1 1 1 1
1 2
1 3
*/