#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;

int n, f[N], in[N], tim, path[N], siz, vis[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int flag = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", f+i);
        ll top = 0, bum = 0;
        memset(vis, 0, sizeof(int) * (n+5));
        tim = 0;
        for (int i = 1; i <= n && flag; i++)
        {
            if (vis[i]) continue;
            int x = i;
            vis[x] = ++tim;
            path[siz = 1] = x;
            while (vis[f[x]] == 0)
            {
                x = f[x];
                vis[x] = tim;
                path[++siz] = x;
            }
            /*cout<<tim<<" lu:";
            for (int i = 1; i <= siz; i++)
                cout<<path[i]<<" ";
            puts("");*/
            if (vis[f[x]] == tim) //当前有新环
            {
                //cout<<"qidian:"<<f[x]<<endl;
                ll fx = f[x], fy = 1;
                for (int j = siz; j; j--)
                {
                    int pre = path[j];
                    if (pre != f[x])
                    {
                        //cout<<"pre:"<<pre<<endl;
                        fx += pre;
                        ++fy;
                    }
                    else break; 
                }
                //cout<<fx<<" "<<fy<<endl;
                ll g = __gcd(fx, fy);
                fx /= g;
                fy /= g;
                if (top == 0)
                {
                    top = fx;
                    bum = fy;
                }
                else
                {
                    if (top != fx || bum != fy)
                        flag = 0;
                }
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
/*
5
10
2 5 5 7 7 6 5 6 9 9
8
2 5 5 7 7 6 5 6
2
1 1
12
10 1 1 9 9 5 8 12 11 8 9 10
2
1 2
*/