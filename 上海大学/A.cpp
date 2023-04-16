#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N][N], fix[N], js[N], cnt[N];
vector <string> vec;

char ans[N];

void dfs(int i, string s)
{
	if (i == 8)
	{
		for (int num = 0; num < 10; num++)
		{
			if (cnt[num] && js[num] < cnt[num]) //��������
				return ; 
			
			if (fix[num] && js[num] != cnt[num]) //���������ޣ��Ҳ���� 
				return ;
		}
		
		for (int pos = 0; pos < 8; pos++) //�������˲��ܳ��ֵ�λ�� 
			if (a[pos][s[pos] - '0']) return ;
		int a1 = (s[0] - '0') * 10 + s[1] - '0';
		int a2 = (s[3] - '0') * 10 + s[4] - '0';
		int a3 = (s[6] - '0') * 10 + s[7] - '0';
		if (a1 + a2 != a3) return ;
		vec.push_back(s);
		return ;
	}
	if (i == 2) {dfs(i + 1, s + "+"); return ;}
	if (i == 5) {dfs(i + 1, s + "="); return ;}
	if (ans[i]) dfs(i + 1, s + ans[i]);
	else
	{
		for (char j = '0'; j <= '9'; j++)
		{
			++js[j - '0'];
			dfs(i + 1, s + j);
			--js[j - '0'];
		}
	}
	
}

string s, t;
int main()
{
	/*
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	*/
	cin>>s>>t;
	for (int i = 0; i < 8; i++)
	{
		if (i == 2 || i == 5) continue;
		if (t[i] == 'P') //��iλ���ܷ� s[i],��cnt++ 
		{
			a[i][s[i] - '0'] = 1;
			++cnt[s[i] - '0'];
		}
		if (t[i] == 'B') //��iλ���ܷ� s[i],��cnt�̶��� 
		{
			a[i][s[i] - '0'] = 1;
			fix[s[i] - '0'] = 1;
		}
		if (t[i] == 'G') //��iλ��Ϊans[i], �̶��� 
			ans[i] = s[i];
	}
	dfs(0, "");
	printf("%d\n", vec.size());
	for (auto aa : vec)
		cout<<aa<<'\n';
	return 0;
}

