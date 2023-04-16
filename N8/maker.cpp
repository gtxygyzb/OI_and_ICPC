#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    srand(time(0));
    int n = 50;
    printf("%d %d %d\n", n, 1, n);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    random_shuffle(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
        printf("%d %d\n", a[i], a[i + rand()%(n - i) + 1]);
}