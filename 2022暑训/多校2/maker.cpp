#include <bits/stdc++.h>
using namespace std;
int p[1000000];
int main()
{
    srand(time(0));
    int T = 1;
    int n = 200000;
    cout<<T<<endl;
    while (T--)
    {
        printf("%d %d\n", n, 100000);
        for (int i = 2; i <= n; i++)
            printf("%d ", rand() * rand() % (i - 1) + 1);
        
        for (int i = 1; i <= 100000; i++)
        {
            //int A = rand() * rand() % 50000 + 50000, B =  rand() * rand() % 50000 + 50000, C =  rand() * rand() % 50000 + 50000;
            int A = 1, B = 1, C = 1;
            printf("%d %d %d\n", A, B, C);
            for (int i = 1; i <= A; i++)
                printf("%d ", rand() * rand() % n + 1);
            puts("");
            for (int i = 1; i <= B; i++)
                printf("%d ", rand() * rand() % n + 1);
            puts("");
            for (int i = 1; i <= C; i++)
                printf("%d ", rand() * rand() % n + 1);
            puts("");
        }
    }
    return 0;
}