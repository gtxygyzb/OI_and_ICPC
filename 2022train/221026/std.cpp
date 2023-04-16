#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int maxn=1e6 + 7;
const ull base = 131;
char s[maxn], t[maxn];
char ma[maxn<<1];
ll mp[maxn<<1], paw[maxn];
ull gap[maxn], hashS[maxn], hashT[maxn];

void init() {
	gap[0] = 1;
	for (int i = 1; i <= 1000000; ++i) {
		gap[i] = gap[i - 1] * base;
	}
}

void makeHash(char *s, ull *hash) {
	int len = strlen(s);
	for (int i = 0; i < len; ++i) {
		hash[i + 1] = hash[i] * base + (ull)s[i];
	}
}

ull getHash(int l, int r, ull *hash) {
	return hash[r + 1] - hash[l] * gap[r - l + 1];
}

void manacher(char *s){
	int len = strlen(s);
	int l=0;
	ma[l++]='$';
	ma[l++]='#';
	for(int i = 0;i < len; ++i){
		ma[l++] = s[i];
		ma[l++] = '#';
	}
	ma[l] = 0;
	ll mx = 0, id = 0;
	for (int i = 0; i < l; ++i){
		mp[i] = mx > i? min(mp[2 * id - i], mx - i) : 1;
		while (ma[i + mp[i]] == ma[i - mp[i]])	mp[i]++;
		if(i + mp[i] > mx){
			mx = i + mp[i];
			id = i;
		}
	}
	for (int i = 1; i < l; i++) {
		paw[(i >> 1) - (mp[i] >> 1)]++;
		paw[(i >> 1)]--;
	}
	for (int i = 1; i < len; ++i) {
		paw[i] += paw[i - 1];
	}
}

void solve() {
	int len = strlen(s);
	int lent = strlen(t);
	int l, r, mid;
	ll ans = 0;
	ll maxx;
	for (int i = 0; i < len - 1; ++i) {
		l = 1, r = i + 1;
		maxx = 0;
		while (l <= r) {
			mid = l + r >> 1;
			if (getHash(i - mid + 1, i, hashS) == getHash(lent - mid, lent - 1, hashT)) {
				maxx = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		ans += maxx * paw[i + 1];
        cout<<maxx<<" "<<paw[i + 1]<<endl;
	}
	printf("%lld\n", ans);
}

int main(){
	init();
	scanf("%s %s", s, t);
	reverse(t, t + strlen(t));
	manacher(s);
	makeHash(s, hashS);
	makeHash(t, hashT);
	solve();
	return 0;
}
