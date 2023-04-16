#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bin[31] = {1}, sum[31] = {1};
int a[100], top, tmp;
int main()
{
    for (int i = 1; i <= 30; i++)
    {
        bin[i] = bin[i-1] * 3;
        sum[i] = bin[i] + sum[i-1];
    }
    int n;
    scanf("%d", &n);
    //if (n == 1) return 0*puts("2");
    while (sum[top] <= n) ++top;
    tmp = top;
    n -= sum[top - 1];
    top = 0;
    while (n)
    {
        a[++top] = n % 3;
        n /= 3;
    }
    for (int i = tmp; i >= 1; i--)
        printf("%d", a[i] == 0 ? 2 : (a[i] == 1 ? 3 : 6));
    puts("");
    return 0;
}