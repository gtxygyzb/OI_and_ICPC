#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}
const int maxn=5005;
int dp[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int n=s.length();
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j+1]+1;
            }
        }
        ll ans=0;
        for(int l=1;l<n;l++)
        {
            vi cnt(n+1);
            int rcnt=0;
            int lcnt=0;
            for(int i=l+2;i<n;i++)
            {
                cnt[dp[l][i]]++;
                if(dp[l][i])
                    rcnt++;
            }
            // dbg(cnt);
            for(int r=l+1;r<n;r++)
            {
                int len=r-l+1;
                rcnt-=cnt[len-1];
                cnt[dp[l][r+1]]--;
                if(dp[l][r+1]>=len) rcnt--;
                int onelen=len-1;
                if(l-onelen>=0)
                    lcnt+=(dp[l-onelen][l]>=onelen);
                ans+=1LL*lcnt*rcnt;
                // dbg(l,r,lcnt,rcnt);
            }
        }
        print(ans);
 
 
    }
}
