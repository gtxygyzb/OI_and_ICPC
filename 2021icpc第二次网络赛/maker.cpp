#include <bits/stdc++.h>
using namespace std;
int n = 10000;
int main()
{
    //freopen("L.in", "w", stdout);
    srand(time(0));
    cout<<n<<" "<<n<<endl;
    for (int i = 1; i <= n; i++)
        printf("%d ", rand()%100 + 1);
    puts("");
    for (int i = 1; i <= n; i++)
    {
        int opt = rand()%2, l = rand()*rand()%n + 1, r = rand()*rand()%n + 1, w;
        if (l > r) swap(l, r);
        if (opt == 0) w = rand()%100 + 1;
        if (opt == 0) printf("%d %d %d %d\n", opt, l, r, w);
        else printf("%d %d %d\n", opt, l, r);
    }
    return 0;
}
