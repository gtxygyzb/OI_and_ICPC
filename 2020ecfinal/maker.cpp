#include <bits/stdc++.h>
using namespace std;
char id()
{
    int x = rand()%62;
    if (x < 26) return 'a' + x;
    if (x < 52) return 'A' + x - 26;
    return '0' + x - 52;
}
int main()
{
    srand(time(0));
    int n = 1000000;
    while (n--)
    {
        printf("%c", id());
    }
    return 0;
}