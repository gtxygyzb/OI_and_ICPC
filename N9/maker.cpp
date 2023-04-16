#include  <bits/stdc++.h>
using namespace  std;

int main()
{
    int n,q;
    srand(time(0));
    n=100000; 
    q=400000;
    printf("%d\n",n);
    for (int i=2;i<=n;i++) {
        int x=rand()%(i-1)+1;
        printf("%d %d\n",i,x);
    }
    printf("%d\n",q);
    for (int i=1;i<=n;i++) {
        int x=rand()%n+1;  
        int l=1ll*rand(); 
        int r=1ll*rand();
        if (l>r) swap(l,r);
        printf("%d %d %d\n",x,l,r);
    }
}