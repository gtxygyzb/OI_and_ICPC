#include <bits/stdc++.h>
using namespace std;
const int N=1e6+50;
typedef long long ll;
 
struct Data
{
    ll x,y;
    Data () {}
    Data (ll _x,ll _y) {x=_x; y=_y;}
    Data operator +(const Data &t) const
    {
        ll ry=y*t.y/__gcd(y,t.y);
        ll rx=ry/y*x+ry/t.y*t.x;
        ll g=__gcd(rx,ry);
        return Data(rx/g,ry/g);
    }
     
    Data operator -(const Data &t) const
    {
        ll ry=y*t.y/__gcd(y,t.y);
        ll rx=ry/y*x-ry/t.y*t.x;
        ll g=__gcd(rx,ry);
        return Data(rx/g,ry/g);
    }
    Data operator *(const Data &t) const
    {
        ll rx=x*t.x;
        ll ry=y*t.y;
        ll g=__gcd(rx,ry);
        return Data(rx/g,ry/g);
    }
    void output()
    {
        cout<<x<<"/"<<y<<endl;
    }
};
 
string is;
 
Data st[N];
char cst[N],s[N];
 
int siz,csiz,n;
 
Data read(int &i,int f)
{
    int x=0,y=0;
    for (;i<n&&s[i]>='0'&&s[i]<='9';i++)
        x=(x<<3)+(x<<1)+s[i]-'0';
    ++i;
    for (;i<n&&s[i]>='0'&&s[i]<='9';i++)
        y=(y<<3)+(y<<1)+s[i]-'0';
    --i;
    x*=f;
    int g=__gcd(x,y);
    return Data(x/g,y/g);
}
 
int rk(char c)
{
    if (c=='*') return 2;
    return 1;
}
 
int main()
{
    ios::sync_with_stdio(false);
    getline(cin,is);
    for (int top=is.size(),i=0;i<top;i++)
        if (is[i]=='+'||is[i]=='-'||is[i]=='*'||is[i]=='/'||is[i]=='('||is[i]==')'|| (is[i]>='0'&&is[i]<='9'))
            s[n++]=is[i];
    for (int p,i=0;i<n;i++)
    {
        p=0;
        if (s[i]=='-')
        {
            if (i==0 || ( (s[i-1]<'0'||s[i-1]>'9') &&s[i-1]!=')') )
            {
                ++i;
                st[++siz]=read(i,-1);
            }
                 
            else p=1;
        }
        else if (s[i]>='0'&&s[i]<='9')
            st[++siz]=read(i,1);
        else p=1;
         
        if (p)
        {
            if (s[i]==')')
            {
                while (cst[csiz]!='(')
                {
                    Data tmp;
                    if (cst[csiz]=='+') tmp=st[siz-1]+st[siz];
                    else if(cst[csiz]=='-') tmp=st[siz-1]-st[siz];
                    else if(cst[csiz]=='*') tmp=st[siz-1]*st[siz];
                    --csiz;
                    --siz;
                    st[siz]=tmp;
                }
                --csiz;
            }
             
            else if (s[i]!='(')
            {
                while (cst[csiz]!='(' && csiz && rk(s[i]) <= rk(cst[csiz]))
                {
                    Data tmp;
                    if (cst[csiz]=='+') tmp=st[siz-1]+st[siz];
                    else if(cst[csiz]=='-') tmp=st[siz-1]-st[siz];
                    else if(cst[csiz]=='*') tmp=st[siz-1]*st[siz];
                    --csiz;
                    --siz;
                    st[siz]=tmp;
                }
            }
             
            if (s[i]!=')') cst[++csiz]=s[i];
        }
         
    }
    while (csiz)
    {
        Data tmp;
        if (cst[csiz]=='+') tmp=st[siz-1]+st[siz];
        else if(cst[csiz]=='-') tmp=st[siz-1]-st[siz];
        else if(cst[csiz]=='*') tmp=st[siz-1]*st[siz];
        else {--csiz; continue;}
        --csiz;
        --siz;
        st[siz]=tmp;
    }
    st[1].output();
    return 0;
}
