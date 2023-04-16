#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int main()
{
    for (ll k=2;k<=1000000000;k++) { 
        ll c=3ll*(k*k-1); 
        ll m=(ll)sqrt(c+0.5);
        if (1ll*m*m==c) { 
            cout<<k<<endl;
        }
    }
}