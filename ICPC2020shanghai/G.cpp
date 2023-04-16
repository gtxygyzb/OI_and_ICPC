#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll odd = (n / 3) * 2 + n % 3;
    cout<<(n * (n - 1) - odd * (odd - 1)) / 2 <<endl;
    return 0;
}