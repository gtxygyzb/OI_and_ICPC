#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n = 10000;
    cout<<n<<endl;
    for (int i = 1; i <= n; i++)
    {
        int p = rand() & 1;
        if (p) printf("+ ");
        else printf("- ");
        printf("%d\n", p ? rand() : rand());
    }
    return 0;
}