#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 50, ad = 1e6, tp = 2e6;
vector <int> vec[N];

int n, k, ans, a[N], top, f[N];

int work()
{
    int ret = 0;
    for (int i = 1; i <= top; i++) f[i] = 0;
    for (int i = 1; i <= top; i++)
    {
        f[i] = max(f[i], f[i - 1] + a[i]);
        ret = max(ret, f[i]);
    }
    return ret;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int x, i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        vec[x + ad].push_back(i);
    }
    for (int i = 0; i <= tp; i++)
    {
        if (vec[i].empty()) continue;
        int j = i - k, pa = vec[i].size();
        if (j < 0 || j > tp || k == 0)
        {
            ans = max(ans, pa);
            continue;
        }
        if (vec[j].empty())
        {
            ans = max(ans, pa);
            continue;
        }
        int pb = vec[j].size();

        int t1 = 0, t2 = 0; top = 0;
        //cout<<"work: "<<i<<" "<<j<<endl;
        while (1)
        {
            while (t1 < pa && t2 < pb && vec[i][t1] < vec[j][t2])
                {a[++top] = -1; ++t1;}
            while (t1 < pa && t2 < pb && vec[i][t1] > vec[j][t2])
                {a[++top] = 1; ++t2;}
            //cout<<t1<<" , "<<t2<<" "<<vec[i][t1]<<" "<<vec[j][t2]<<endl;
            if (t1 == pa)
            {
                while (t2 < pb) {a[++top] = 1; ++t2;}
                break;
            }
            if (t2 == pb)
            {
                while (t1 < pa) {a[++top] = -1; ++t1;}
                break;
            }
        }
        ans = max(ans, pa + work());
    }
    printf("%d\n", ans);
    return 0;
}