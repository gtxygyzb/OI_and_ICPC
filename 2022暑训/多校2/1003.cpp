#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int MAXN=1e6+10;

int a[MAXN];
int to[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            to[i]=i;
        }
        int ans=0;
        while(q--)
        {
            int op;
            scanf("%d",&op);
            if(op==1)
            {
                int l,r;
                scanf("%d%d",&l,&r);
                for(int i=r+1;i<=n;i++)
                {
                    to[i]=to[i-(r-l+1)];
                }
            }
            else
            {
                int x;
                scanf("%d",&x);
                //printf("asd  %d\n",a[to[x]]);
                ans^=a[to[x]];
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}
/*
1
5 4      
1 2 3 4 5
2 4
1 2 4
1 4 4
2 5
*/