#include <bits/stdc++.h>
#define hhh printf("hhh\n")
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
inline int read() {int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}

const int maxn = 4e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-7;

int n;
int a[maxn];
int stk[maxn], idx[maxn], top;
int fa[maxn], len[maxn];
map<int,int> ch[maxn];
int last, tot;
ll pre[maxn], ans;

void init() {
    for(int i=1; i<=tot; ++i) ch[i].clear(), fa[i]=0;
    last=tot=1, top=0, ans=0;
}

void add(int c, int pos) {
    int p=last, np=last=++tot;
    len[np]=len[p]+1;
    for(; p&&!ch[p][c]; p=fa[p]) ch[p][c]=np;
    if(!p) fa[np]=1;
    else {
        int q=ch[p][c];
        if(len[q]==len[p]+1) fa[np]=q;
        else {
            int nq=++tot;
            fa[nq]=fa[q], len[nq]=len[p]+1, ch[nq]=ch[q];
            fa[np]=fa[q]=nq;
            for(; p&&ch[p][c]==q; p=fa[p]) ch[p][c]=nq;
        }
    } //前面是普通的后缀自动机，下面是统计加入当前字符后新增本质不同的子串对答案的贡献
    int st=len[np]-len[fa[np]]; //新增的本质不同的串的首字符下标从1到st，尾字符都是当前新增字符
    int l=1, r=top, m=(l+r)/2; //计算从哪里开始利用前缀和，利用前缀和就是加速的关键！我也不知道我怎么想到的，简直妙呀！
    while(l<r) {
        if(idx[m]>=st) r=m;
        else l=m+1;
        m=(l+r)/2;
    }
    ans+=pre[m-1]+1ll*stk[m]*(st-idx[m-1]); //这个答案统计就简单啦
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    int T=read();
    while(T--) {
        init();
        int n=read();
        for(int i=1; i<=n; ++i) a[i]=read();
        for(int i=1; i<=n; ++i) {
            while(top&&stk[top]<=a[i]) top--;
            ++top, stk[top]=a[i], idx[top]=i, pre[top]=pre[top-1]+1ll*a[i]*(idx[top]-idx[top-1]); //维护单调栈，并且记录单调栈中每个数在原串中的下标，再记录单调栈中每个数到栈底对答案的贡献，也就是一个前缀和（这一点不好理解）
            add(a[i],i);
        }
        printf("%lld\n", ans);
    }
}
