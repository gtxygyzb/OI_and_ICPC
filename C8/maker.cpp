#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int T= 5;
    cout<<T<<endl;
    for (int cs = 1; cs <= T; cs++)
    {
        int P = 1000;
        int n = 10, m = 10;
        cout<<n<<endl;
        for (int i = 1; i <= n; i++)
            printf("%d ", rand()*rand()%P + 1);
        cout<<endl<<m<<endl;
        for (int i = 1; i <= m; i++)
        {
            int l = rand()*rand()%n + 1;
            int r = rand()*rand()%n + 1;
            if (l > r) swap(l, r);
            printf("%d %d %d\n", rand()%3 + 1, l, r);
        }
    }
    return 0;
}