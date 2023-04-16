#include <bits/stdc++.h>

#define del(x, y) (((pre2[x] + pre3[y] - pre4[x][y]) % MOD + MOD) % MOD)
using namespace std;
const int N = 1000001, M = 62, MOD = 998244353;
char a[N];
int mp[200], tot, pos[M], n;
int suf1[M], suf2[N][M], suf3[N][M], suf4[N][M];
int pre1[M], pre2[M], pre3[M], pre4[M][M], ans;

inline void add(int &x, int y) {
    x += y;
    while (x > MOD) x -= MOD;
}

int main() {
    for (int i = 0; i < 26; i++) mp['a' + i] = tot++;
    for (int i = 0; i < 26; i++) mp['A' + i] = tot++;
    for (int i = 0; i < 10; i++) mp['0' + i] = tot++;
    scanf("%s", a + 1), n = strlen(a + 1);
    for (int i = n, x; i >= 3; i--) {
        x = mp[a[i]], suf1[x]++;
        for (int y = 0; y < tot; y++) {
            if (y == x) continue;
            add(suf2[i][y], suf2[pos[x]][y] + suf1[y]);
            add(suf3[i][y], suf3[pos[x]][y] + suf2[pos[y]][x]);
            suf4[i][y] = suf3[pos[y]][x];
        }
        pos[x] = i;
    }
    for (int i = 1, x, all = 0; i <= n - 3; i++) {
        x = mp[a[i]], pre1[x]++;
        add(all, i - pre1[x]);
        add(pre3[x], i - pre1[x]);
        for (int y = 0; y < tot; y++) {
            if (y == x) continue;
            add(pre2[y], pre1[y]);
            add(pre4[y][x], pre1[y]);
        }
        if (i < 2) continue;
        for (int y = 0, z; y < tot; y++) {
            if (y == (z = mp[a[i + 1]])) continue;
            add(ans, 1ll * (((all - del(z, y) - del(y, z)) % MOD + MOD) % MOD) * suf4[i + 1][y] % MOD);
        }
    }
    printf("%d\n", ans);
    cout<<clock()<<endl;
    return 0;
}