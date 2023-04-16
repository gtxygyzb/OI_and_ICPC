#include <bits/stdc++.h>
using namespace std;
#define fi firset
#define se second 
#define pb push_back
#define ln printf("\n");
typedef long long ll; 
const int maxn=4e6+100; 
const ll mod=998244353;
const int inf=1e9;
const double pi=acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;

const int N=4000010;
const double eps=1e-6,PI=acos(-1);

int n;
int rev[N],p[N];
int bit,limit;
ll c[N],fac[N],inv[N];

struct Complex {
	double x,y;
	Complex operator + (const Complex& t) const { return {x+t.x,y+t.y}; }
	Complex operator - (const Complex& t) const { return {x-t.x,y-t.y}; }
	Complex operator * (const Complex& t) const { return {x*t.x-y*t.y,x*t.y+y*t.x}; } 
}a[N],b[N];

void fft(Complex a[],int inv) {
	for(int i=0;i<limit;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int mid=1;mid<limit;mid<<=1) {
		Complex w1=Complex({cos(PI/mid),inv*sin(PI/mid)});
		for(int i=0;i<limit;i+=mid*2) {
			Complex wk=Complex({1,0});
			for(int j=0;j<mid;j++,wk=wk*w1) {
				Complex x=a[i+j],y=wk*a[i+j+mid];
				a[i+j]=x+y; a[i+j+mid]=x-y;
			}
		}
	}
}

ll power(ll a,ll b)
{
    ll ret = 1;
    for (;b;b>>=1, a = a *a %mod)
        if (b&1) ret = ret * a % mod;
    return ret;
}
int main()
{
    int n;
    fac[0]=1;  int N=1000010;
    for (int i=1;i<=N;i++) {
        fac[i]=1ll*fac[i-1]*i%mod;
    }
    ll ans=1;
    inv[0]=1; inv[N]=power(fac[N],mod-2);
    for (int i=N-1;i>=1;i--) {
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    scanf("%d",&n);
    int x;
    for (int i=1;i<=n;i++) {
        scanf("%d",&x);
        ans*=inv[i];
        ans%=mod;
        ans*=inv[x];
        ans%=mod; ans*=fac[x+1]; ans%=mod;
        a[x].x=1;
		b[1000000-x].x=1;
    }
	while((1<<bit)<=2000000) bit++;
	limit=1<<bit;
    //cout<<limit<<endl;
	for(int i=0;i<limit;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	fft(a,1); fft(b,1);
   // return 0;
	for(int i=0;i<limit;i++) a[i]=a[i]*b[i];
	fft(a,-1);
    //return 0;
    for(int i=500000*2;i<=2*1000000;i++) if((ll)(a[i].x/limit+0.5)>0) c[i-1000000]=(ll)(a[i].x/limit+0.5);
    /*for (int i=1;i<=10;i++) {
        printf("%lld ",c[i]);
    }
    printf("\n");*/
    ll ret=1;
    for (int i=1;i<=1000000;i++) {
        ans*=power(1ll*i,c[i]);
        ret*=power(1ll*i,c[i]);
        ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}
