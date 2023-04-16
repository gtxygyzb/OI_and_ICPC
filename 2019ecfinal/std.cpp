#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#define lowbit(x) ( x&(-x) )
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
#define HalF (l + r)>>1
#define lsn rt<<1
#define rsn rt<<1|1
#define Lson lsn, l, mid
#define Rson rsn, mid+1, r
#define QL Lson, ql, qr
#define QR Rson, ql, qr
#define myself rt, l, r
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uit;
typedef long long ll;
inline bool lessthan(int e1, int e2) { return e1 > e2; }
inline bool is_num(int ch) { return ch >= '0' && ch <= '9'; }
inline int read(int &x)
{
    char ch = getchar();
    while((ch ^ '-') && !is_num(ch)) ch = getchar();
    if(ch == '-') { x = -1; return x; }
    x = ch - '0';
    while(is_num(ch = getchar())) x = x * 10 + ch - '0';
    return x;
}
const int maxN = 305;
int N;
int done_Time[maxN][10], Wa_num[maxN][10], cnt[maxN], pen_time[maxN], solve_time[maxN][10];
int need_time[10], need_wa[10];
int minn_solve_all, minn_solve[10], maxx_solve_all;
inline bool cmp(int e1, int e2)
{
    if(cnt[e1] ^ cnt[e2]) return cnt[e1] > cnt[e2];
    if(pen_time[e1] ^ pen_time[e2]) return pen_time[e1] < pen_time[e2];
    for(int i=0; i<cnt[e1]; i++) if(solve_time[e1][i] ^ solve_time[e2][i]) return solve_time[e1][i] < solve_time[e2][i];
    return e1 > e2;
}
int perm[10], cnt_N, other_rank[maxN];
inline int Get_Rank()
{
    int l = 1, r = N - 1, ans = 0, mid;
    while(l <= r)
    {
        mid = HalF;
        if(cmp(N, other_rank[mid])) r = mid - 1;
        else
        {
            l = mid + 1;
            ans = mid;
        }
    }
    return ans + 1;
}
inline void init()
{
    minn_solve_all = INF; maxx_solve_all = 0; cnt_N = 0;
    for(int i=0; i<10; i++) minn_solve[i] = INF;
}
int main()
{
    //freopen("std.out", "w", stdout);
    read(N);
    init();
    for(int i=1; i<N; i++)
    {
        cnt[i] = pen_time[i] = 0;
        for(int j=0; j<10; j++)
        {
            if(~read(done_Time[i][j]))
            {
                read(Wa_num[i][j]);
                solve_time[i][cnt[i]++] = done_Time[i][j];
                pen_time[i] += done_Time[i][j] + 20 * Wa_num[i][j];
                maxx_solve_all = max(maxx_solve_all, done_Time[i][j]);
                minn_solve_all = min(minn_solve_all, done_Time[i][j]);
                minn_solve[j] = min(minn_solve[j], done_Time[i][j]);
            }
        }
        sort(solve_time[i], solve_time[i] + cnt[i], lessthan);
        other_rank[i] = i;
    }
    sort(other_rank + 1, other_rank + N, cmp);
    for(int i=0; i<10; i++)
    {
        if(~read(need_time[i]))
        {
            read(need_wa[i]);
            perm[cnt_N++] = i;
        }
    }
    int ans = 0, tmp_ans, tim_now, rk;
    do
    {
        tmp_ans = 0; tim_now = 0;
        pen_time[N] = cnt[N] = 0;
        for(int i=0; i<cnt_N; i++)
        {
            if(tim_now + need_time[perm[i]] > 300) break;
            //cout<<perm[i]<<" ";
            tim_now += need_time[perm[i]];
            pen_time[N] += tim_now + need_wa[perm[i]] * 20;
            solve_time[N][cnt[N]++] = tim_now;
            if(tim_now <= minn_solve[perm[i]]) {tmp_ans += 800; /*cout<<"yixue:"<<endl;*/}
            if(!i && tim_now <= minn_solve_all) {tmp_ans += 700; /*cout<<"quanchang"<<endl;*/}
        }
        //puts("\n");
        if(cnt[N] && tim_now >= maxx_solve_all) {tmp_ans += 500; /*cout<<"pingbo"<<endl;*/}
        for(int i = 0, j = cnt[N] - 1; i < j; i++, j--) swap(solve_time[N][i], solve_time[N][j]);
        rk = Get_Rank();
        tmp_ans += 5000 / rk; //cout<<"pm: "<<5000/rk<<endl;
        if(rk <= N / 10) {tmp_ans += 1200; /*cout<<"jin1200"<<endl;*/}
        else if(rk <= 3 * N / 10) {tmp_ans += 800; /*cout<<"ying800"<<endl;*/}
        else if(rk <= 6 * N / 10) {tmp_ans += 400; /*cout<<"tong400"<<endl;*/}
        ans = max(ans, tmp_ans);
        //cout<<rk<<":"<<tmp_ans<<endl;
        //puts("--------------");
    } while(next_permutation(perm, perm + cnt_N));
    printf("%d\n", ans);
    return 0;
}
/*
2
1 0,-,-,-,-,-,-,-,-,-
1 0,-,-,-,-,-,-,-,-,-
*/