#include <bits/stdc++.h>
using namespace std;

const int N = 8e3 + 50;

int n, NN;

int st[N], top, f[N][N];
int tree[N][8200], pre[N], a[N];

void cmin(int &x, int y) {x = min(x, y);}

int query(int id, int l, int r)
{
    int ans = 1e9;
    for (l += NN - 1, r += NN + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
    {
        if (~l & 1) cmin(ans, tree[id][l ^ 1]);
        if (r & 1) cmin(ans, tree[id][r ^ 1]);
    }
    return ans;
}
void change(int id, int x, int d)
{
    for (int i = x + NN; i; i >>= 1) 
        cmin(tree[id][i], d);
}
void build()
{
	for (int j = 1; j <= n; j++)
	{
	    for (int i = 1; i <= n; ++i)
	        tree[j][i + NN] = 1e9;
	    for (int i = NN; i; --i)
	        tree[j][i] = 1e9;
	}
}


int main()
{
    scanf("%d", &n);
    
    NN = 1 << __lg(n + 5) + 1;
    cout<<NN<<endl;
    
    int mx = -1e9;
    memset(f, 0x3f, sizeof(f));
    build();
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        mx = max(a[i], mx);
        f[i][1] = mx;
        while (top && a[st[top]] < a[i]) --top;
        pre[i] = top ? st[top] : -1;
        st[++top] = i;
        
        change(1, i, f[i][1]);
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (pre[i] >= j)
            {
                f[i][j] = min(f[i][j], f[pre[i]][j]);
            	
            }

            f[i][j] = min(f[i][j], query(j - 1, max(j - 1, pre[i]), i - 1) + a[i]);
            change(j, i, f[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d\n", f[n][i]);
    return 0;
}
