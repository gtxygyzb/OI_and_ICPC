#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
string s;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        cin>>s;
        int p;
        while ((p = s.find("std::make_tuple")) >= 0)
        {
            s.erase(p, 15);
            //cout<<p<<" "<<s<<endl;
        }
        /*if ((p = s.find("std::make_tuple")) >= 0)
        {
            s.erase(p - 1, 15);
            cout<<p<<" "<<s<<endl;
        }*/
        cout<<s<<endl;
    }
    return 0;
}
/*
1
std::make_tuple(-2,3,3,std::make_tuple(3,3))
*/