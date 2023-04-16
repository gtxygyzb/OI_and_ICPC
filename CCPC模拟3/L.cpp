#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 50;
int vis[N], tot, pri[N];

double ln[N];
double f[N];
void init()
{
    for (int i = 2; i <= N - 50; i++)
    {
        if (vis[i] == 0) {pri[++tot] = i;}
        for (int j = 1; j <= tot; j++)
        {
            if (i * pri[j] > N - 50) break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) break;
        }
    }
    for (int i = 1; i <= N - 50; i++)
        ln[i] = log(i);
    for (int i = 1; i <= tot; i++)
        for (int j = N-50; j >= pri[i]; j--)
            for (int k = pri[i]; k <= j; k *= pri[i])
                f[j] = max(f[j], f[j - k] + ln[k]);
}

double dp(int n)
{
    memset(f, 0, sizeof(f));
}

int main()
{
    init();
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%.8lf\n", f[n]);
    }
    return 0;
}