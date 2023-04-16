#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<unordered_map>
#include<cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;

int a[MAXN];
int tp[30];
map<int, int> mp;

struct trie {
    int nex[MAXN][2], cnt;
    bool exist[MAXN]; 
    void init()
    {
        memset(nex, 0, sizeof(nex));
        memset(exist, 0, sizeof(exist));
        cnt = 0;
    }
    void insert(int a) {  

        int l = 0;
        while (a)
        {
            tp[l++] = a & 1;
            a >>= 1;
        }
        for (int i = l; i < 30; i++) tp[l] = 0;
        int p = 0;
        for (int i = 0; i < 30; i++) {
            int c = tp[i];
            if (!nex[p][c]) nex[p][c] = ++cnt; 
            p = nex[p][c];
        }
        exist[p] = 1;
    }
    void dfs(int p,ll now,ll tp)
    {
    	//cout<<p<<" "<<now<<" "<<tp<<endl; 
        if (nex[p][1])
        {
            dfs(nex[p][1], now + (1ll << tp), tp + 1);
        }
        if (nex[p][0])
        {
            dfs(nex[p][0], now, tp + 1);
        }
        if (exist[p])
        {
            for (int i = 0; i < mp[now]; i++)
            {
                printf("%lld ", now);
            }
        }
    }
}t;

void solve()
{
    int n;
    scanf("%d", &n);
    mp.clear();
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        mp[x]++;
    } 
    t.init();
    for (P p : mp)
    {
        if (p.second >= 3)
        {
            puts("NO");
            return;
        }
        t.insert(p.first);
    }
    puts("YES");
    t.dfs(0, 0, 0);
    puts("");
}

int main()
{
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}
/*
2
2
1000000000 999999999
1
13213
*/
