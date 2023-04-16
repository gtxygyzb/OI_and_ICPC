#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 50;
int n, k, a[N], ans[N];

vector < pair<int, int> > vec, aec;

bool cmp()
{
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] < a[i]) return 1;
        if (ans[i] > a[i]) return 0;
    }
    return 0;
}
void getans()
{
    if (ans[1] == 0)
    {
        for (int i = 1; i <= n; i++)
            ans[i] = a[i];
        aec = vec;
    }
    else if (cmp())
    {
        for (int i = 1; i <= n; i++)
            ans[i] = a[i];
        aec = vec;
    }
}
void dfs(int dep)
{
    if (dep == k)
    {
        getans();
        return ;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            /*cout<<i<<" , "<<j<<endl;
            for (int l = 1; l <= n; l++)
                cout<<a[l]<<" ";
            puts("------------");*/
            
            int tmp = a[i];
            for (int k = i; k < j; k++)
                a[k] = a[k + 1];
            a[j] = tmp;

            /*for (int l = 1; l <= n; l++)
                cout<<a[l]<<" ";
            puts("");*/

            vec.push_back(make_pair(i, j));
            dfs(dep + 1);
            vec.pop_back();

            tmp = a[j];
            for (int k = j; k > i; k--)
                a[k] = a[k - 1];
            a[i] = tmp;
        }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(ans, 0, sizeof(ans));
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);
        
        dfs(0);

        //puts("---------------");
        for (int i = 1; i <= n; i++)
        {
            if (i == 1) printf("%d", ans[i]);
            else printf(" %d", ans[i]);
        }
        puts("");
        /*cout<<endl;
        for (int i = 0; i < aec.size(); i++)
            cout<<aec[i].first<<" "<<aec[i].second<<endl;
        puts("---------------");*/
    }
    return 0;
}
/*
1
7 1
3 1 4 2 4 1 1 
*/