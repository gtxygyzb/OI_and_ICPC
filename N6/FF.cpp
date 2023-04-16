#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if (n == 3)
    {
        puts("1");
        puts("1 2 3");
        return 0;
    }
    if (n & 1)
        --n;
    int ans = 0;
    for (int i = 1; i <= n; i += 2)
        for (int j = i + 2; j <= n; j +=2)
            ans += 2;
    cout<<ans<<endl;
    for (int i = 1; i <= n; i += 2)
        for (int j = i + 2; j <= n; j +=2)
        {
            printf("%d %d %d\n", i, i + 1, j);
            printf("%d %d %d\n", i, i + 1, j + 1);
        }
    return 0;
}