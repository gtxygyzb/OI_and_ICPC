#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = (m); i <= (n); ++i)
#define dop(i, m, n) for(int i = (m); i >= (n); --i)
//#define submit
using namespace std;
const int N = 300010;
int n, m, cnt = 1, pre[N];
struct node{
	int id, val;
	int operator < (const node A) const{
		return val < A.val;
	}
}a[N];
struct Trie{
	int ch[2], val, pos;
	Trie(){
		ch[0] = ch[1] = val = pos = 0;
	}
	int operator < (const Trie A) const{
		return val != A.val ? val < A.val : pos < A.pos;
	}
}t[N * 31], tmp;
Trie get(int x){
	int u = 1;
	Trie ans;
	dop(i, 30, 0){
		int p = (x >> i & 1) ^ (m >> i & 1);
		if(!t[u].ch[p]) 
			if(m >> i & 1)
				return ans;
			else return max(ans, t[t[u].ch[!p]]);
		if(!(m >> i & 1)) chkmax(ans, t[t[u].ch[p^1]]);
		u = t[u].ch[p];
	}
	return max(ans, t[u]);
}
void insert(int x, int y, int z){
	int u = 1;
	dop(i, 30, 0){
		int p = x >> i & 1;
		if(!t[u].ch[p]) t[u].ch[p] = ++cnt;
		u = t[u].ch[p];
		if(y > t[u].val || y == t[u].val && z > t[u].pos){
			t[u].val = y, t[u].pos = z;
		}
	}
}
int ans, pos;
void print(int x){
	if(pre[x]) print(pre[x]);
	printf("%d ", a[x].id);
}
int main(){
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i].val), a[i].id = i;
	sort(a+1, a+n+1);
	rep(i, 1, n){
		tmp = get(a[i].val);
		pre[i] = tmp.pos;
		if(tmp.pos) tmp.val += tmp.val ? 1 : 2; 
		if(tmp.val > ans){
			ans = tmp.val;
			pos = i;
		}
		insert(a[i].val, tmp.val, i);
	}
	printf("%d\n", ans ? ans : -1);
	if(ans) print(pos);
	return 0;
}

