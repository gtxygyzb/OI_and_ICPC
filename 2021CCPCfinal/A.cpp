#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;

char ch[10], v[10];
struct Data
{
    int op, val;
    void input()
    {
        scanf("%s", ch);
        if (ch[0] == 'e')
        {
            op = 1;
            scanf("%s", v);
            val = (int) v[0];
        }
        else
        {
            scanf("%d", &val);
            op = 2;
        }
    }
}a[N];
queue <Data> q;
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        a[i].input();
        q.push(a[i]);
    }
    int cnt = 1;
    while (!q.empty() && cnt <= k)
    {
        Data u = q.front(); q.pop();
        if (u.op == 1)
            printf("%c", (char)(u.val));
        else
        {
            if (cnt + q.size() <= k)
                for (int i = 1; i <= u.val; i++)
                    q.push(a[i]);
        }
        ++cnt;
    }
    return 0;
}
/*
3 100000
echo a
echo b
cp 2
*/