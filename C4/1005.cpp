#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 50, P = 1e9+7;
int fi[N][20],fx[N][20],l,r,a[N],m,n;

int querymi(int i,int j)
{
    int s=int(log(j-i+1)/log(2));
    return (min(fi[i][s],fi[j+1-(1<<s)][s]));
}
int querymx(int i,int j)
{
    int s=int(log(j-i+1)/log(2));
    return (max(fx[i][s],fx[j+1-(1<<s)][s]));
}
int power(int x, int k)
{
    int ret = 1;
    for (; k; k >>= 1, x = 1LL * x * x % P)
        if (k & 1) ret = 1LL * ret * x % P;
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &m, &n);
        for (int i=1;i<=m;i++) cin>>a[i];
        for (int i=1;i<=m;i++) fi[i][0]=fx[i][0]=a[i];
        
        for (int j=1;j<=log(m)/log(2);j++)
            for (int i=1;i<=m+1-(1<<j);i++)
            {
                fi[i][j]=min(fi[i][j-1],fi[i+(1<<(j-1))][j-1]);
                fx[i][j]=max(fx[i][j-1],fx[i+(1<<(j-1))][j-1]);
            }
        for (int l, r, i=1;i<=n;i++)
        {
            scanf("%d%d", &l, &r);
            int sum = querymi(l, r) + querymx(l, r);
            cout<<"sum:"<<sum<<endl;
            printf("%d\n", 1LL * sum * power(r - l + 1, P - 2) % P);
        }
    }
    return 0;
}
/*
10 3
1 2 3 4 5 6 7 8 9 10
2 7
3 9
1 10
*/