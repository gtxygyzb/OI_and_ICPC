#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e4 + 50;
int n;
 
struct Data
{
    int s[10], val;
    bool operator <(const Data &t) const {return val < t.val;}
}a[N];
 
int bl[10][4], cnt[10], ding[10], bin[15];
vector <int> C[11][11];
 
int dfs(int dep, int b[], int bsiz)
{
	int ret = 0;
    if (dep == n + 1)
    {
    	ret = 1;
        for (int sum, i = 0; i < 10; i++)
            ret *= cnt[i];
        return ret;
    }
    int sc = 0;
    for (int i = 0; i < 10; i++)
        if (cnt[i] == 1 && a[dep].s[i] == ding[i]) ++sc;
        
    if (sc > a[dep].val) return 0;
    if (bsiz == 0 && sc != a[dep].val) return 0;
    if (bsiz == 0) return dfs(dep + 1, b, bsiz);
    
    int k = a[dep].val - sc; //在b(bsiz)里选k个数 
    for (auto p : C[bsiz][k]) //p是一个长度为bsiz的01串 
    {
    	int tb[15], tc[15], hs[15], ht = 0, top = 0, flag = 1;
    	
    	for (int i = 0; i < 10; i++) //保存cnt 
    		tc[i] = cnt[i];
    		
    	for (int j = 0; j < bsiz; j++) 
    	{
    		int u = b[j]; //第u位具体是哪一位 
    		if (p & bin[j]) //选 
    		{
				if (bl[u][a[dep].s[u]]) //没有受到之前条件的约束 
				{
    				ding[u] = a[dep].s[u];
    				cnt[u] = 1;
    			}
    			else flag = 0;
    		}
    		else // 该位不能选 
    		{
				tb[top++] = u; 
				if (bl[u][a[dep].s[u]])
				{
					--cnt[u]; hs[ht++] = u;
					bl[u][a[dep].s[u]] = 0;
				}
			}
    	}
    	
    	if (flag) ret += dfs(dep + 1, tb, bsiz - k);
    	for (int j = 0; j < ht; j++) //bl回溯 
    	{
    		int u = hs[j]; 
			bl[u][a[dep].s[u]] = 1;
    	}
    	for (int i = 0; i < 10; i++) //cnt回溯 
    		cnt[i] = tc[i];
    }
    return ret;
}
 
void prework()
{
	bin[0] = 1;
    for (int i = 1; i <= 10; i++)
    	bin[i] = bin[i - 1] << 1;
    for (int i = 1; i <= 10; i++)
    {
    	for (int j = 0; j < bin[i]; j++)
    		C[i][__builtin_popcount(j)].push_back(j);
    }
}
string ch;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    prework();
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        map <string, bool> mp;
        int top = 0; 
        for (int val, i = 1; i <= n; i++)
        {
            cin >> ch >> val;
            if (!mp[ch])
            {
                mp[ch] = 1; ++top;
                for (int j = 0; j < 10; j++)
                    a[top].s[j] = ch[j] - 'A';
                a[top].val = val / 10;
            }
        }
        n = top;
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        int b[10];
        for (int i = 0; i < 10; i++)
        {
            b[i] = i, cnt[i] = 4;
            for (int j = 0; j < 4; j++)
            	bl[i][j] = 1;
        }
        printf("%d\n", dfs(1, b, 10));
    }
    return 0;
}
/*
1
2
AAAAAAAAAA 10
ABCDABCDAB 20
*/