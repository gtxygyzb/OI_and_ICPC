#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int T = 10000;
    cout<<T<<endl;
    while (T--)
    {
        int n = 4, s = rand()%2, t = rand()%(2+1), h = rand()%10 + 1;
        printf("%d %d %d %d\n", n, s, t, h);
        for (int i = 1; i < n; i++)
            printf("%d ", rand()*rand()%h + 1);
        puts("");
        for (int i = 1; i < n; i++)
            printf("%d ", rand()*rand()%h + 1);
        puts("");
        puts("");
    }
    return 0;
}
/*
10 0 1 7
7 6 6 5 4 6 4 7 6 
1 4 6 5 2 2 6 1 1 
*/