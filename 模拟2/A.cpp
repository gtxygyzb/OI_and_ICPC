#include <bits/stdc++.h>
using namespace std;
int tot, a[] = {1, 6, 28, 88, 198, 328, 648}, b[] = {8, 18, 28, 58, 128, 198, 388};
int ans;
int main()
{
    scanf("%d", &tot);
    int n = 7;
    for (int i = 0; i < (1<<n); i++)
    {
        int t = 0, val = 0;
        for (int j = 0; j < n; j++)
            if (i & (1<<j))
            {
                t += a[j];
                val += b[j];
            }
        if (t <= tot)
            ans = max(ans, val);
    }
    cout<<tot*10+ans<<endl;
    return 0;
}