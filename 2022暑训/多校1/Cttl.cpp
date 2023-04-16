#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int MAXN=1e6+10;

int T,n,m;
int v[2000],w[2000];
bitset<1024> dp[2][1100];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",v+i,w+i);
        }

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 1024; j++)
                dp[i][j].reset();

        dp[0][0] = 1;
        //dp[1][w[1]]= 1 | (1<<v[1]);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=1023;j++)
            {
                dp[i & 1][j] = dp[!(i & 1)][j];
                dp[i & 1][j]|= dp[!(i & 1)][j^w[i]]<<v[i];
            }
        }
        int t = -1;
        for(int i=1023;i>=0;i--)
        {
            if(dp[n & 1][i][m])
            {
                printf("%d\n",i);
                t = 1;
                break;
            }
        }
        if (t != 1) puts("-1");
    }


    return 0;
}
/*
3
5 4
2 4
1 6
2 2
2 12
1 14

3 3
3
1
2
*/