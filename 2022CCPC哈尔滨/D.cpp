#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 50;
 
ll read(int cnt[], int s[], int &top)
{
    ll x = 0; char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) ;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
    {
        x = x * 10 + ch - '0';
        ++cnt[ch - '0'];
        s[top++] = ch - '0';
    }
    return x;
}
 
int cntp[10], cntq[10], nump[25], numq[25], tp, tq;
int nq[25], top;
ll ansp, ansq;
void init()
{
    tp = tq = 0;
    memset(cntp, 0, sizeof(cntp));
    memset(cntq, 0, sizeof(cntq));
    memset(nump, 0, sizeof(nump));
    memset(numq, 0, sizeof(numq));
}
int bin[25] = {1}, n, lo[N];
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= 20; i++)
        bin[i] = bin[i - 1] << 1;
    for (int i = 2; i < N; i *= 2)
        lo[i] = lo[i >> 1] + 1;
    while (T--)
    {
        init();
        ll p, q;
        p = read(cntp, nump, tp);
        q = read(cntq, numq, tq); // num 从0到t-1
        ansp = p; ansq = q;
        n = tp; //保留哪些数
        for (int i = 1; i < bin[n] - 1; i++) //保留为1
        {
            __int128 dp = 0;
            int d[10] = {0}, a[10] = {0};
            for (int j  = i; j; j -= j & -j)
            {
                int pos = (j & -j);
                dp = dp * 10 + nump[lo[pos]];
                ++d[nump[lo[pos]]];
            }
            if (dp == 0) continue;
            __int128 tmp = dp * q;
            if (tmp % p) continue;
 
            ll dq = tmp / p; top = 0;
            for (ll x = dq; x; x /= 10)
            {
                ++a[x % 10];
                nq[top++] = x % 10;
            }
            int pi = 0, len = 0;
            for (int j = tq - 1; ~j; j--)
            {
                if (numq[j] == nq[pi]) ++pi;
                if (pi == top)
                {
                    for (int k = 0; k < j; k++)
                        if (numq[k] == 0) ++len;
                    break;
                }
            }
            if (pi != top) continue;
                
            int flag = 1;
            for (int i = 0; i <= 9 && flag; i++)
            {
                int ddp = cntp[i] - d[i], ddq = cntq[i] - a[i];
                if (ddp != ddq)
                {
                    if (i == 0 && ddq - ddp > 0 && ddq - ddp <= len) continue;
                    flag = 0;
                }
            }
            if (flag)
            {
                ansp = min(ansp, (ll)(dp));
                ansq = min(ansq, dq);
            }
        }
        printf("%lld %lld\n", ansp, ansq);
    }
    return 0;
}