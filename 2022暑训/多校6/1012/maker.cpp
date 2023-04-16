#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int T = 10;
    cout<<T<<endl;
    while (T--)
    {
        int n = 8, k = rand() % 4 + 1;
        printf("%d %d\n", n, k);
        for (int i = 1; i <= n; i++)
            printf("%d ", rand()% 4 + 1);
        puts("");
    }
    return 0;
}