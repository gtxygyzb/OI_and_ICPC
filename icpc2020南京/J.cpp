#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 50;
char s[N], c;
int n, m;
vector <int> vec[N];
int cnt[200], ans;
set <int> se;

int read()
{
    int x = 0; char ch = getchar();
    for (;ch < '0' || ch > '9'; ch = getchar()) ;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return x;
}
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int l, r, i = 1; i <= m; i++)
    {
        l = read(); r = read();
        c = getchar();
        vec[l].push_back(c);
        vec[r + 1].push_back(-c);
    }
    for (int i = 1; i <= n; i++)
    {
        int siz = vec[i].size();
        for (int j = 0; j < siz; j++)
        {
            int t = vec[i][j];
            if (t > 0)
            {
                ++cnt[t];
                if (cnt[t] == 1)
                    se.insert(t);
            }
            if (t < 0)
            {
                --cnt[-t];
                if (cnt[-t] == 0)
                    se.erase(-t);
            }
        }
        if (!se.empty())
        {
            set <int>::iterator it = se.end();
            --it;
            ans += max((int)(s[i]), *it);
        }
        else ans += s[i];
    }
    printf("%d\n", ans);
    return 0;
}
/*
5 5
aaaaa
1 2 c
1 2 d
2 4 c
2 4 c
1 5 c
*/