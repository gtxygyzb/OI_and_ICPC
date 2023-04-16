#include <bits/stdc++.h>
using namespace std;
const int N = 250, P = 998244353;
int n, a[N][N], b[N][N], bin[N] = {1}, ans = 1;

bitset <N> c[N];

int guass()
{
    int ret = 0;
    for (int i = 1, p = 1; i <= n; i++)
    {
        int mx = p;
        if (!c[mx][i])
            for (int j = p + 1; j <= n; j++)
                if (c[j][i]) {mx = j; break;}
        if (!c[mx][i]) {++ret; continue;}
        swap(c[mx], c[p]);
        for (int j = p + 1; j <= n; j++)
            if (c[j][i])
                c[j] ^= c[p];
        ++p;
    }
	return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        bin[i] = 1LL * 2 * bin[i - 1] % P;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &b[i][j]);
        
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                c[i][j] = a[i][j];
        for (int i = 1; i <= n; i++)
            c[i][i] = (c[i][i] != b[i][k]);
        /*puts("-----------");
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout<<c[i][j]<<" ";
            puts("");
        }*/
        ans = 1LL * ans * bin[guass()] % P;
    }
    cout<<ans<<endl;
    return 0;
}