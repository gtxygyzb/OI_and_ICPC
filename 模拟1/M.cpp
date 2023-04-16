 #include <bits/stdc++.h>
 using namespace std;

 int x[9], y[9], ax[9], ay[9];
 int main()
 {
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        int ans = 0;
        ax[0] = ax[1] = ay[0] = ay[1] = 0;
        scanf("%d%d", &n, &m);
        for (int t, i = 1; i <= n; i++)
        {
            scanf("%d", &t);
            ax[t] = 1;
        }
        for (int t, i = 1; i <= m; i++)
        {
            scanf("%d", &t);
            ay[t] = 1;
        }
        for (int i = 1; i <= 15; i++)
        {
            x[0] = x[1] = y[0] = y[1] = 0;
            for (int j = 0; j < 4; j++)
            {
                if ((1<<j) & i)
                {
                    x[j / 2] = 1;
                    y[j % 2] = 1;
                }
            }
            if (x[0] == ax[0] && x[1] == ax[1] && y[0] == ay[0] && y[1] == ay[1])
                ++ans;
        }
        cout<<ans<<endl;
    }
    return 0;
 }