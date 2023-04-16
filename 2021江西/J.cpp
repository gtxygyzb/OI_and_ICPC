#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
struct Data
{
    int val, tim;
    bool operator <(const Data &t) const {return tim < t.tim;}
};
int n, k, a[N];
bool check(int siz)
{
    int ret = 0;
    map <int, int> mp;
    set <Data> se;
    for (int i = 1; i <= n; i++)
    {
        if (mp[a[i]])
        {
            ++ret;
            se.erase(Data{a[i], mp[a[i]]});
            mp[a[i]] = i;
            se.insert(Data{a[i], i});
            continue;
        }
        if (se.size() == siz)
        {
            Data top = *se.begin();
            se.erase(se.begin());
            mp.erase(top.val);
        }
        mp[a[i]] = i;
        se.insert(Data{a[i], i});
    }
    return ret >= k;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int l = 1, r = n, ans = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    if (ans == -1) puts("cbddl");
    else printf("%d\n", ans);
    return 0;
}