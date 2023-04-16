#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vec;
typedef pair < vec , int> pa;
const int N = 5e5 + 50;

vec ling;
struct Trie
{
	int top, ch[N][10], cnt[N];
	vec sum[N];
	void init()
	{
		for (int i = 1; i <= top; i++)
		{
			memset(ch[i], 0, sizeof(ch[i]));
			cnt[i] = 0;
			sum[i].clear();
		}	
		top = 1;
		sum[1] = ling;
	}
	void insert(vec a)
	{
		int u = 1;
		for (int c, i = 0; i < 10; i++)
		{
			c = a[i];
			if (!ch[u][c])
			{
				ch[u][c] = ++top;
				sum[top] = ling;
			}
			u = ch[u][c];
			//cout<<u<<" "<<c<<endl;
			++cnt[u];
			for (int j = i; j < 10; j++)
				sum[u][j] = (sum[u][j] + a[j]) % 10;
		}
	}
	void del(vec a)
	{
		int u = 1, pre;
		for (int c, i = 0; i < 10; i++)
		{
			c = a[i];
			pre = u;
			u = ch[u][c];
			--cnt[u];
			for (int j = i; j < 10; j++)
			{
				sum[u][j] -= a[j];
				if (sum[u][j] < 0) sum[u][j] += 10;
			}
			if (cnt[u] == 0) ch[pre][c] = 0;
		}
	}
	void query(vec a)
	{
		int u = 1, ans[15], at = 0;
		for (int i = 0; i < 10; i++)
		{
			int x = 9 - a[i];
			for (int cs = 1, c = x; cs <= 10; c--, cs++)
			{
				if (c < 0) c = 9;
				if (ch[u][c])
				{
					u = ch[u][c];
					ans[at++] = c; break;
				}
			}
			//cout<<"ans:"<<ans[at-1];
		}
		for (int i = 0; i < 10; i++)
			ans[i] = (ans[i] + a[i]) % 10;
		int i = 0;
		while (i < at && ans[i] == 0) ++i;
		if (i == at) {puts("0"); return ;}
		for (; i < at; i++)
			printf("%d", ans[i]);
		puts("");
	}
	pa qsum(int u, int d, vec a, int lim)
	{
		//cout<<u<<" "<<d<<" "<<a[d]<<" "<<lim<<endl;
		if (d == 10)
		{
			vec ret = ling;
			ret[d - 1] = a[d - 1] * cnt[u] % 10;
			return pa(sum[u], cnt[u]);
		}
		if (lim == 0)
		{
			/*for (int j = 0; j < 10; j++)
				cout<<sum[u][j];
			puts("");*/
			return pa(sum[u], cnt[u]);
		}
		int tt = lim ? a[d] : 9;
		vec ret;
		for (int j = 0; j < 10; j++)
			ret.push_back(0);
		/*cout<<"tt:"<<tt<<endl;
		system("pause");*/
		int cc = 0;
		for (int i = 0; i <= tt; i++)
		{
		 	if (ch[u][i] == 0) continue;
		 	//cout<<"i:"<<i<<endl;
		 	pa tmp = qsum(ch[u][i], d + 1, a, lim && (i == a[d]));
		 	vec ad = tmp.first;
		 	for (int j = 0; j < 10; j++)
		 		ret[j] = (ret[j] + ad[j]) % 10;
		 	if (lim && d > 0)
		 	{
			 	ret[d - 1] = (ret[d - 1] + a[d - 1] * tmp.second) % 10;
		 		cc += tmp.second;
		 	}
		}
		return pa(ret, cc);
	}
	void output()
	{
		for (int i = 2; i <= top; i++)
		{
			cout<<i<<": ";
			for (int j = 0; j < 10; j++) cout<<sum[i][j];
			cout<<" "<<cnt[i];
			puts("");
		}
	}
}trie;

vec divid(int x)
{
	vec ret;
	for (int i = 0; i < 10; i++, x /= 10)
		ret.push_back(x % 10);
	reverse(ret.begin(), ret.end());
	return ret;
}
int n, m;
queue <int> q;
void init()
{
	trie.init();
	while (!q.empty()) q.pop();
}
void add()
{
	int x;
	scanf("%d", &x);
	vec a = divid(x);
	trie.insert(a);
	if (x) q.push(x);
}
int main()
{
	for (int j = 0; j < 10; j++)
		ling.push_back(0);
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++)
	{
		init();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			add();
		//trie.output();
		printf("Case #%d:\n", cs);
		for (int x, y; m--;)
		{
			char opt[10];
			scanf("%s", opt);
			if (opt[0] == 'A')
			{
				add();
				//trie.output();
			}
			if (opt[1] == 'h') //shift
			{
				int tot = q.size(); 
				for (int i = 0; i < tot; i++)
				{
					int u = q.front(); q.pop();
					vec a = divid(u);
					trie.del(a);
					u /= 10;
					a = divid(u);
					trie.insert(a);
					if (u) q.push(u);
				}
			}
			if (opt[0] == 'Q') //query
			{
				scanf("%d", &x);
				vec a = divid(x);
				trie.query(a);
			}
			if (opt[2] == 'm') //sum
			{
				scanf("%d%d", &x, &y);
				vec l, r = divid(y);
				vec r1 = trie.qsum(1, 0, r, 1).first, r2;
				/*for (int i = 0; i < 10; i++)
					cout<<r1[i];
				puts("");*/
				if (x != 0)
				{
					l = divid(x - 1);
					r2 = trie.qsum(1, 0, l, 1).first;
					/*for (int i = 0; i < 10; i++)
						cout<<r2[i];
					puts("");*/
					for (int j = 0; j < 10; j++)
					{
		 				r1[j] -= r2[j];
		 				if (r1[j] < 0) r1[j] += 10;
		 			}
				}
				vec ans = r1;
				int i = 0;
				while (i < 10 && ans[i] == 0) ++i;
				if (i == 10) puts("0");
				else
				{
					for (; i < 10; i++)
						printf("%d", ans[i]);
					puts("");
				}
			}
		}
	}
	return 0;
}
/*
1
50 1
69 64 42 83 60 60 34 7 35 100 56 45 24 82 62 78 94 8 83 33 10 32 64 36 24 14 12 17 77 78 5 24 26 88 14 31 27 25 100 16 32 43 32 63 50 84 90 12 79 85 
Sum 17 78
*/
