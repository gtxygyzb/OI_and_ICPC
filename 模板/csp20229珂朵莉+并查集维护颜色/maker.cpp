#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n = 10, m = 3, q = 10000;
    cout<<n<<" "<<m<<" "<<q<<endl;
    while (q--)
    {
        int op = rand() % 5 + 1;
        int x = rand() * rand() % n  + 1, y = rand() * rand() % n + 1;
        int u = rand() % m + 1, v = rand() % m;
        if (x > y) swap(x, y);
        if (op == 1) printf("1 %d %d %d\n", x, y, u);
        if (op == 2) printf("2 %d %d\n", u, v);
        if (op == 3) printf("3 %d %d\n", u, v + 1);
        if (op == 4) printf("4 %d\n", u);
        if (op == 5) puts("5");
    }
}