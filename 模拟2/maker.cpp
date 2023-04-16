#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    //freopen("test.in", "w", stdout);
    int n = 10;
    for (int i = 1; i <= n; i++)
        printf("%d ", rand()*rand() % 1000000 + 1);
    for (int i = 1; i <= n; i++)
        printf("\n%d %d", i, i + (rand()*rand() % (n-i + 1) + 1));
    return 0;
}