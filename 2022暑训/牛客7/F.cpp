#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int n, x, a[N], del[N], pre[N], nxt[N];
int ans, vis[N];
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a+i);
        nxt[i] = i % n + 1;
        pre[i] = i - 1;
        if (pre[i] == 0) pre[i] = n;
    }
    for (int i = 1; ; i = nxt[i])
    {
        ++vis[i];
        if (vis[i] > 1) break;
        if (del[i]) continue;
        //cout<<i<<endl;
        while (ans * 2 < n && i != pre[i] && (a[i] == a[pre[i]] || a[i] + a[pre[i]] == x))
        {
            ++ans;
            del[i] = 1;
            del[pre[i]] = 1;
            nxt[pre[pre[i]]] = nxt[i];
            pre[nxt[i]] = pre[pre[i]];
            i = pre[pre[i]];
        }
        /*cout<<"st: "<<i<<endl;
        int j;
        for (j = i; nxt[j] != i; j = nxt[j])
        {
            cout<<a[j]<<" ";
        }
        cout<<a[j]<<endl;*/
    }
    printf("%d\n", ans);
    
    
    return 0;
}
/*
19 5
1 1 4 4 1 4 2 3 1 2 1 3 4 1 2 4 3 4 5
*/