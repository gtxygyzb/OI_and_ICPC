#include <bits/stdc++.h>
using namespace std;
string a, b;
int main()
{
	cin>>a>>b;
	if (a < b) cout<<a<<"<"<<b;
	else if (a == b) cout<<a<<"="<<b;
	else cout<<a<<">"<<b;
	return 0;
}
