#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e6 + 50;

int n, f[N];
int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

int ch[N][26], mx[N], fa[N], last, top = 1, t[N], rk[N];
int add(int last, int c)
{
    if (ch[last][c] && mx[last] + 1 == mx[ch[last][c]])
        return ch[last][c];

    int p = last, np = ++top;
    mx[np] = mx[p] + 1;
    for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
    if (!p) fa[np] = 1;
    else
    {
        int q = ch[p][c];
        if (mx[q] == mx[p] + 1) fa[np] = q;
        else
        {
            int nq = p == last ? np : ++top;
            mx[nq] = mx[p] + 1;
            memcpy(ch[nq], ch[q], sizeof(ch[q]));
            for (;p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
            fa[np] = nq;
            fa[nq] = fa[q];
            fa[q] = nq;
        }
    }
    return np;
}

vector <int> vec[N];
char s[N];
int merge(int x, int y)
{
    x = find(x), y = find(y);
    return x != y ? (f[y] = x, 1) : 0;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        f[i] = i;
        last = 1;
        for (int lim = strlen(s), j = 0; j < lim; j++)
        {
            last = add(last, s[j] - 'a');
            vec[last].push_back(i);
            //cout<<last<<": "<<i<<endl;
        }
    }
    ll ans = 0;
    //cout<<"top: "<<top<<endl;
    for (int i = 1; i <= top; i++) ++t[mx[i]];
    for (int i = 1; i <= top; i++) t[i] += t[i - 1];
    for (int i = top; i >= 1; i--) rk[t[mx[i]]--] = i;
    for (int i = top; i >= 2; i--)
    {
        int u = rk[i], rt = -1, cnt = 0;
        for (int j = 0; j < vec[u].size(); j++)
        {
            if (~rt) cnt += merge(rt, vec[u][j]);
            else rt = vec[u][j];
        }
        if (~rt) vec[fa[u]].push_back(rt);
        //cout<<u - 1<<" "<<mx[u]<<" "<<cnt<<" "<<fa[u]<<endl;
        ans += 1ll * mx[u] * cnt;
    }
    printf("%lld\n", ans);
    return 0;
}
/*
3
dada
adab
bc

*/