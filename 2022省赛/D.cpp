#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
const int mod=5999993;
typedef long long ll;
char s[N];


ll gethas(char s[],ll len)
{
	ll res=0;
	for(int i=0;i<len;i++)
	{
		res=(res*29+(s[i]-'a'+1))%mod;
	}
	return res;
}

int main()
{
	

	int a[] = {8, 14, 8, 24, 9, 10, 9};
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		printf("%s", s);
		for (int i = 0; i < 7; i++)
			printf("%c", (char)(a[i] + 'a' - 1));
		ll hs=gethas(s,strlen(s));
		vector<char> v;
		
	}
	return 0;
}
/*
2
c
n
*/
