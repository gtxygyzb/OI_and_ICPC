#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int a= rand()%8 + 2, b = rand()%8 + 2;
    cout<<a<<" "<<b<<" "<<rand()*rand() % (a*b)/2 + 1;
    return 0;
}