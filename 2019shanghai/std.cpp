#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define sz(a) ((int)a.size())
const int maxn = 1e4 + 5;
const int maxm = 2e5 + 5;

char sum[maxm][10], s[10], ss[10], ret[10];
int nxt[maxm][10], laz[maxm];
int a[maxn];
int n, m, cnt;

int add(){

    ++cnt, memset(nxt[cnt], 0, sizeof nxt[cnt]);
    memset(sum[cnt], '0', sizeof sum[cnt]), laz[cnt] = 0;
    return cnt;
}

void conv(int x, char *s){

    int n = 10;
    for( ; x; x /= 10) s[--n] = x % 10 + '0';
    while(n > 0) s[--n] = '0';
}

ll ston(char *s){

    ll ret = 0;
    for(int i = 0; i < 10; ++i) ret = ret * 10 + (s[i] - '0');
    return ret;
}

void pluss(char *s1, char *s2){

    for(int i = 0; i < 10; ++i){

        s1[i] = s1[i] + s2[i] - '0';
        if(s1[i] > '9') s1[i] -= 10;
    }
}

void subtract(char *s1, char *s2){

    for(int i = 0; i < 10; ++i){

        s1[i] = s1[i] - s2[i] + '0';
        if(s1[i] < '0') s1[i] += 10;
    }
}

void divide(int p, int d){

    d = min(d, 10);
    for(int i = 9; i >= d; --i) sum[p][i] = sum[p][i - d];
    for(int i = 0; i < d; ++i) sum[p][i] = '0';
}

void pushDown(int p){

    if(laz[p]){

        for(int i = 0; i < 10; ++i){

            int v = nxt[p][i];
            if(!v) continue;
            laz[v] += laz[p];
            divide(v, laz[p]);
        }
        laz[p] = 0;
    }
}

void insert(char *s){

    int p = 0; pushDown(p);
    for(int i = 0; i < 10; ++i){

        int t = s[i] - '0';
        if(!nxt[p][t]) nxt[p][t] = add();
        pluss(sum[p], s);
        p = nxt[p][t];
        pushDown(p);
    }
    pluss(sum[p], s);
}

void shift(){

    int p = 0, np = add();
    divide(p, 1);
    memcpy(nxt[np], nxt[p], sizeof nxt[p]);
    memcpy(sum[np], sum[p], sizeof sum[p]);
    laz[np] = laz[p] + 1;
    memset(nxt[p], 0, sizeof nxt[p]);
    nxt[p][0] = np;
    laz[p] = 0;
}

void queryMax(char *x, char *ret){

    int p = 0; pushDown(p);
    for(int i = 0; i < 10; ++i){

        int ch = x[i] - '0', t = -1;
        for(int j = 9; j >= 0; --j){

            t = (j - ch + 10) % 10;
            if(nxt[p][t]) break;
        }
        ret[i] = (t + ch) % 10 + '0';
        p = nxt[p][t];
        pushDown(p);
    }
}

void querySum(char *x, char *ret){

    memset(ret, '0', 10);
    int p = 0; pushDown(p);
    for(int i = 0; i < 10; ++i){

        int t = x[i] - '0';
        for(int j = 0; j < t; ++j){

            int v = nxt[p][j];
            if(!v) continue;
            pluss(ret, sum[v]);
        }
        p = nxt[p][t];
        if(!p) break;
        pushDown(p);
    }
}

void init(){

    cnt = -1; add();
}

int main(){
 
    ios::sync_with_stdio(0); cin.tie(0);
    int t, cas = 0; cin >> t;
    while(t--){

        cin >> n >> m;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        init();
        for(int i = 1; i <= n; ++i){

            conv(a[i], s);
            insert(s);
        }
        cout << "Case #" << ++cas << ":\n";
        while(m--){

            char opt[10]; int x, y; cin >> opt;
            if(opt[2] == 'd'){

                cin >> x;
                conv(x, s);
                insert(s);
            }
            else if(opt[2] == 'i'){

                shift();
            }
            else if(opt[2] == 'e'){

                cin >> x;
                conv(x, s);
                queryMax(s, ret);
                ll ans = ston(ret);
                cout << ans << "\n";
            }
            else{

                cin >> x >> y;
                conv(++y, s);
                querySum(s, ret);
                conv(x, s);
                querySum(s, ss);
                subtract(ret, ss);
                ll ans = ston(ret);
                cout << ans << "\n";
            }
        }
    }
    return 0;
}

