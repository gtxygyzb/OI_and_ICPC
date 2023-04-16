#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n = 11;
    cout<<n<<endl;
    for (int i = 1; i <= n; i++)
    {
        printf("%c ", rand()%2 ? '*' : '+');
        printf("%d\n", (rand()%20 + 2) * (rand()%2 ? 1 : -1));
    }
}