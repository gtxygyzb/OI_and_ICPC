/* LittleFall : Hello! */
#include <bits/stdc++.h>
using namespace std; using ll = long long;
const int M = 5016, MOD = 1000000007;
namespace IO {
  const int MAXSIZE = 1 << 18 | 1;
  char buf[MAXSIZE], *p1, *p2;

  inline int Gc() {
    return p1 == p2 &&
      (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)? EOF: *p1++;
  }
  template<typename T> inline void read(T& x) {
    x = 0; int f = 0, ch = Gc();
    while (!isdigit(ch)) f |= ch == '-', ch = Gc();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = Gc();
    if (f) x = -x;
  }

  inline int read(char* s) {
    int lgt = 0, ch = Gc();
    while (isspace(ch)) ch = Gc();
    while (!isspace(ch)) s[++lgt] = ch, ch = Gc();
    return s[lgt + 1] = '\0', lgt;
  }
}
using IO::read;
int toque[M];
int que[M][M];
ll LRU_hash[M][M];  
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
    #endif
    int T;
	read(T);
	while(T--)
	{
		int n, q;
		read(n), read(q);
		memset(que[0], 0, (n+1)*sizeof(que[0][0]));
		for(int i=1, qlen=0; i<=n; ++i)
		{
			memcpy(que[i], que[i-1], (n+1)*sizeof(que[0][0]));
			int now, pos = 0;
			read(now);
			for(int j=1; j<=qlen; ++j)
				if(que[i][j]==now)
					pos = j, j = qlen+1;
			for(int j=(pos?pos:++qlen); j; --j)
				que[i][j] = que[i][j-1];
			que[i][1] = now;

			for(int j=1; j<=n; ++j)
				LRU_hash[i][j] = (LRU_hash[i][j-1]*(n+1)+que[i][j])%MOD;
		}
		while(q--)
		{
			int m; read(m);
			ll hashv = 0;
			for(int i=1; i<=m; ++i)
			{
				read(toque[i]);
				hashv = (hashv*(n+1)+toque[i])%MOD;
			}
			int suc = 0;
			for(int i=0; i<=n; ++i) if(LRU_hash[i][m]==hashv)
			{
				int flag = 1;
				for(int j=1; j<=m; ++j)
					if(que[i][j]!=toque[j])
						flag = 0, j = m+1;
				if(flag)
					suc = 1, i=n+1;
			}
			printf("%s\n",suc?"Yes":"No" );
		}
	}

    return 0;
}

