#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;
const ll inf = 1e18;
int a[N], b[N];
ll f1, f2;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll ans = inf;
        int n, s, t, h;
        scanf("%d%d%d%d", &n, &t, &s, &h);
        for (int i = 1; i < n; i++)
            scanf("%d", a+i);
        for (int i = 1; i < n; i++)
            scanf("%d", b+i);
        sort(a + 1, a + n);
        sort(b + 1, b + n);
        ll s1 = 0, s2 = 0, t1, t2;
        for (int i = s + 1; i < n - t ; i++)
            s1 += a[i], s2 += b[i];
        //cout<<s1<<" "<<s2<<endl;
        ll st1, ed1, st2, ed2;

        st1 = s ? a[s] : 1;
        st2 = s ? b[s] : 1;
        ed1 = t ? a[n - t] : h;
        ed2 = t ? b[n - t] : h;

        for (int k1 = 1; k1 <= 3; k1++)
        {
            if (k1 == 1 && s == 0) continue;
            if (k1 == 2 && t == 0) continue;

            if (k1 == 1 && s)
                f1 = 1, t1 = s1 + a[s];
            if (k1 == 2 && t)
                f1 = a[n - t], t1 = s1 + a[n - t];
            if (k1 == 3) t1 = s1;

            for (int k2 = 1; k2 <= 3; k2++)
            {
                int ck = 1;
                if (k1 == 3) f1 = -1;
                if (k2 == 1 && s == 0) continue;
                if (k2 == 2 && t == 0) continue;

                if (k2 == 1 && s)
                    f2 = b[s], t2 = s2 + b[s];
                if (k2 == 2 && t)
                    f2 = h, t2 = s2 + b[n - t];
                
                if (k2 == 3)
                {
                    if (f1 == -1) //两个给分必须在 [st1,ed1], [st2, ed2]之间
                    {
                        ll del = s2 - s1 + 1; //a的打分至少比b多del
                        ll mxdel = ed1 - st2; //极限情况，a的打分最多比b多mxdel
                        ll midel = st1 - ed2; //极限情况，最小的差值
                        if (mxdel >= del) //合法的呢
                        {
                            //cout<<"3,3"<<endl;
                            ans = min(ans, max(del, midel));
                        }
                        ck = 0;
                    }
                    else //a已经有分了, b在[st2, ed2]之间
                    {
                        ll del = t1 - s2; // a比b多的分数，即给b的分在不能超过del - 1
                        if (del - 1 >= st2)
                        {
                            //cout<<"ay,b3"<<endl;
                            f2 = min(ed2, del - 1);
                            ans = min(ans, f1 - f2);
                        }
                        ck = 0;
                    }
                }
                else if (f1 == -1) //b给分了, a在[st1, ed1]之间
                {
                    ll del = t2 - t1 + 1; // a至少要给del分
                    /*cout<<"bf:"<<f2<<endl;
                    cout<<"bgei,ano"<<" "<<del<<" "<<t2<<" "<<t1<<endl;*/
                    if (del <= ed1)
                    {
                        f1 = max(st1, del);
                        ans = min(ans, f1 - f2);
                    }
                    ck = 0;
                }
                if (ck && t1 > t2)
                {
                    //cout<<"ruleo:"<<k1<<" "<<k2<<" "<<f1<<" "<<f2<<endl;
                    ans = min(ans, f1 - f2);
                }
            }
        }
        if (ans == inf) puts("IMPOSSIBLE");
        else printf("%lld\n", ans);
    }
    return 0;
}
/*
1
5 1 1 3
2 1 3 3 
2 2 1 2 
*/