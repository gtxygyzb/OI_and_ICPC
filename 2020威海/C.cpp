#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
struct Trie
{
    int val[N], ch[N][26], tot;
    int all[N], siz[N], del[N];
    void init()
    {
        for (int i = 0; i <= tot; i++)
        {
            memset(ch[i], 0, sizeof(ch[i]));
            val[i] = 0;
        }
        tot = 0;
    }
    int add(char *s, int x)
    {
        int u = 0;
        for (int len = strlen(s), i = 0; i < len; i++)
        {
            if (!ch[u][s[i] - 'a'])
                ch[u][s[i] - 'a'] = ++tot;
            u = ch[u][s[i] - 'a'];
        }
        if (val[u] && val[u] != x) return 0;
        val[u] = x;
        return 1;
    }
    void work(int u)
    {
        for (int i = 0; i < 26; i++)
            if (ch[u][i]) work(ch[u][i]);
        siz[u] = 1; all[u] = -1;
        del[u] = 0;
        if (val[u] == 0) //find the size max val
        {
            map <int, int> mp;
            int flag = 0;
            for (int v, i = 0; i < 26; i++)
            {
                if ((v = ch[u][i]) == 0) continue;
                if (!all[v]) continue;
                flag = 1;
                mp[val[v]] += siz[v];
                //if (u == 0) cout<<"q0: "<<v<<" "<<val[v]<<" "<<siz[v]<<" "<<map[val[v]]<<endl;
            }
            if (flag)
            {
                int mx = 0;
	            for (int v, i = 0; i < 26; i++)
	            {
	                if ((v = ch[u][i]) == 0) continue;
	                if (!all[v]) continue;
	                if (mp[val[v]] > mx)
	                {
	                	mx = mp[val[v]];
	                	val[u] = val[v];
	            	}
	            }
	        }
        }
        
        if (val[u])
        {
        	all[u] = val[u];
        	for (int v, i = 0; i < 26; i++)
	        {
	            if ((v = ch[u][i]) == 0) continue;
	            if (!all[v]) {all[u] = 0; siz[u] += siz[v]; continue;}
	            if (all[v] != val[u])
	            {
	            	siz[u] += siz[v];
	            	all[u] = 0;
	            }
                else {/*cout<<"del:"<<v<<endl;*/ del[v] = 1;}
	        }
        }
        else
        {
			all[u] = 0;
			for (int v, i = 0; i < 26; i++)
            {
                if ((v = ch[u][i]) == 0) continue;
	            siz[u] += siz[v];
            }
		}
        //cout<<u<<":"<<val[u]<<" "<<siz[u]<<" "<<all[u]<<" "<<endl;
    }
    void check()
    {
        int flag = 1;
        map <int, int> mp;
        for (int i = 0; i <= tot && flag; i++)
        {
            if (del[i] || val[i] == 0) continue;
            if (mp[val[i]]) flag = 0;
            mp[val[i]] = 1;
        }
        printf("%d\n", flag ? siz[0] : -1);
    }
}trie;

char s[N];
int main()
{
    int n, T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++)
    {
        trie.init();
        scanf("%d", &n);
        int flag = 1;
        for (int val, i = 1; i <= n; i++)
        {
            scanf("%s%d", s, &val);
            flag &= trie.add(s, val);
        }
        printf("Case #%d: ", cs);
        if (flag == 0) {puts("-1"); continue;}
        trie.work(0);
        trie.check();
    }
    return 0;
}
/*
1
7
a 1
aa 1
aaa 1
aba 1
abb 1
aba 1
aca 1
*/