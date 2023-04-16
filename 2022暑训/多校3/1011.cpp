#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int MAXN=1e6+10;
const int mod=998244353;

struct node
{
    ll x,y,w;
}a[MAXN];
bool cmp(node x,node y)
{
    return x.w<y.w;
}

ll mx[4][MAXN];
ll w[MAXN];
ll tp[4];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        ll rr=-INF;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].w);
            rr=max(a[i].w,rr);
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++) w[i]=a[i].w;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=3;j++)
            {
                ll x=INF,y=INF;
                if(j&1) x*=-1;
                if((j>>1)&1) y*=-1;
                mx[j][i]=abs(x-a[i].x)+abs(y-a[i].y);
            }
        }
        for(int i=n-1;i>=1;i--)
        {
            for(int j=0;j<=3;j++)
            {
                mx[j][i]=max(mx[j][i],mx[j][i+1]);
            }
        }

        rr++;
        while(q--)
        {
            ll x,y;
            scanf("%lld%lld",&x,&y);
            ll lb=0,rb=rr;
            while(rb-lb>1)
            {
                ll mid=lb+rb>>1;
                int pos=lower_bound(w+1,w+n+1,mid)-w;
                if(pos>n)
                {
                    rb=mid;
                }
                else
                {
                    ll ans=-INF;
                    for(int i=0;i<=3;i++)
                    {
                        ll xx=INF,yy=INF;
                        if(i&1) xx*=-1;
                        if((i>>1)&1) yy*=-1;
                        tp[i]=abs(x-xx)+abs(y-yy);
                        ans=max(ans,mx[i][pos]-tp[i]);
                    }
                    if(ans>=mid) lb=mid;
                    else rb=mid;
                }
            }

            printf("%lld\n",lb);


        }
    }


    return 0;
}
