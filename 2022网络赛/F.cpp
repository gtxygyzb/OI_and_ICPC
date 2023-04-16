#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, a[N], nxt[N];

int work(int l, int r)
{
    int num1 = nxt[l] - 1, num2 = n - r + 1;
    int num3 = n - num1 - num2;
    //cout<<l<<" "<<r<<":: "<<num1<<" "<<num2<<" "<<num3<<endl;
    return max(num1, max(num2, num3)) - min(num1, min(num2, num3));
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);
        sort(a + 1, a + n + 1);
        int cur = n + 1;
        for (int i = n; i >= 1; i--)
        {
            nxt[i] = cur;
            if (a[i] != a[i - 1])
            cur = i;
        }

        int ans = 1e9, l = 1, r = 1;
        for (; l <= n; l = nxt[l])
        {
            while (work(l, r) >= work(l, nxt[r]))
                r = nxt[r];
            ans = min(ans, work(l, r));
        }
        printf("%d\n", ans);
    }
}
/*
1
7
1 1 2 3 3 3 4
*/