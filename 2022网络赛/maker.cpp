#include <bits/stdc++.h>
using namespace std;
const int N = 1E6 + 50;
char ch[N];
int main()
{
    srand(time(0));
    int T = 100;
    cout<<T<<endl;
    for (int i = 1; i <= T; i++)
    {
        int n = rand() % 20000 + 1;
        printf("%d %d\n", n, rand() * rand() % (n / 26) + 1);

        for (int i = 1; i <= n; i++)
            ch[i] = rand()%26 + 'a';
        for (int i = 1; i <= n; i++)
            printf("%c", ch[i]);
        puts("");
    }
    return 0;
}