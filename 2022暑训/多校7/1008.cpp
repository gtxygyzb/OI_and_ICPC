#include <bits/stdc++.h>
using namespace std;
const int N = 2e2;
int f[N][N][N];

int dfs(int a, int b, int c) //a>b>c
{
    if (b > a && b > c) swap(a, b);
    else if (c > a && c > b) swap(a, c);

    if (c > b) swap(b, c);
    if (b + c <= a) return -1;
    //cout<<"g: "<<a<<" "<<b<<" "<<c<<" "<<f[a][b][c]<<endl;
    //cout<<"guocheng: "<<a<<" "<<b<<" "<<c<" "<< f[a][b][c] <<'\n';
    if (~f[a][b][c]) return f[a][b][c];
    for (int i = 1; i < a; i++)
    {
        int t = dfs(a - i, b, c);
        if (t == 0) f[a][b][c] = 1;
    }
    if (f[a][b][c] != 1)
        for (int i = 1; i < b; i++)
        {
            int t = dfs(a, b - i, c);
            if (t == 0) f[a][b][c] = 1;
        }
    if (f[a][b][c] != 1)
        for (int i = 1; i < c; i++)
        {
            int t = dfs(a, b, c - i);
            if (t == 0) f[a][b][c] = 1;
        }
    if (f[a][b][c] == -1) f[a][b][c] = 0;
    return f[a][b][c];
        
}
int main()
{
    memset(f, -1, sizeof(f));
    f[1][1][1] = 0;
    
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= i; j++)
            for (int k = 1; k <= j; k++)
            {
                if (f[i][j][k] == -1) f[i][j][k] = dfs(i, j, k);
                if (f[i][j][k] == 0) printf("%d %d %d\n", i, j, k);
            }
    return 0;
}