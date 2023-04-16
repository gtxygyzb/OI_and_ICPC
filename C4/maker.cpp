#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n = 1e5, m = 1e5;
    cout<<1<<endl;
    cout<<n<<" "<<m<<" "<<1e5<<endl;
    for (int i = 1; i <= 1e5; i++)
        printf("%d %d\n", rand()*rand()%n + 1, rand()* rand()%n + 1);
}