#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1e5 + 50;
const ull seed = 131;

int n, s[N][10], val[N], ans, a[N];
ull fin;
map <ull, int> mp;

void dfs(int dep, int op)
{
    if (dep == 5)
    {
        ull h = 0;
        for (int i = 1; i <= n; i++)
        {
            ull v = 0;
            int x = op == 1 ? 0 : 5;
            int y = op == 1 ? 5 : 10;

            for (int j = x; j < y; j++)
                if (s[i][j] == a[op == 1 ? j : j - 5]) ++v;
            h = h * seed + v;
        }
        //cout<<"h:"<<h<<endl;
        if (op == 1) ++mp[h];
        else
        {
            ans += mp[fin - h];
        }
        return ;
    }
    for (int j = 0; j < 4; j++)
    {
        a[dep] = j;
        dfs(dep + 1, op);
    }
}

string ch;
int main()
{
	//ios::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
	int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        mp.clear();
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> ch >> val[i];
            for (int j = 0; j < 10; j++)
                s[i][j] = ch[j] - 'A';
            val[i] /= 10;
        }
        fin = 0;
        for (int i = 1; i <= n; i++)
            fin = fin * seed + val[i];
        dfs(0, 1);
        //puts("--------");
        dfs(0, 2);
        printf("%d\n", ans);
    }
	return 0;
}
/*
3
1
CCCCCCCCCC 90
*/
