#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1e6 + 50, seed = 131;
int n, k, a[N], c[N];
char s[N];
map <ull, bool> mp;

ull calc(int x)
{
    ull ret = 0, p = 1;
    while (x)
    {
        ret += (x & 1) * p;
        x >>= 1;
        p *= seed;
    }
    return ret;
}
ull power(int k)
{
    ull ret = 1, x = 131;
    for (; k; k >>= 1, x = x * x)
        if (k & 1) ret = ret * x;
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%s", &n, &k, s);
        int len = strlen(s);
        for (int i = 0; i < len; i++)
            a[i] = s[i] == '0';
        ull val = 0;
        mp.clear();
        for (int i = 0; i < k; i++)
            val = val * seed + a[i];
        //cout<<"val:"<<val<<endl;
        mp[val] = 1;
        ull sp = power(k - 1);
        for (int i = k; i < len; i++)
        {
            val = (val - a[i - k] * sp) * seed + a[i];
            mp[val] = 1;
            //cout<<"val:"<<val<<endl;
        }
        int ans = -1;
        int lim = min(k, 20);
        for (int i = 0; i < (1<<lim); i++)
        {
            ull cur = calc(i);
            //cout<<"cur:"<<cur<<endl;
            if (!mp[cur]) {ans = i; break;}
        }
        if (ans == -1) puts("NO");
        else
        {
            int top = k;
            while (ans)
            {
                a[top--] = ans & 1;
                ans >>= 1;
            }
            while (top) a[top--] = 0;
            puts("YES");
            for (int i = 1; i <= k; i++)
                printf("%d", a[i]);
            puts("");
        }
        
    }
    return 0;
}
/*
1
30 30
111111111111111111111111111111
*/