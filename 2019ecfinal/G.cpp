#include <bits/stdc++.h>
using namespace std;
const int N = 350, inf = 0x3f3f3f3f;
int pmi[N], mi = inf, mx;

int read()
{
    char ch = getchar(); int x = 0;
    for (;ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-') return -1;
    for (;ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x;
}
struct Data
{
    int num, tim, sol[15]; //题数 总时间 解题时间(降序排序后)
    int x[15], y[15], id; //解题时间与罚时
    void init() {num = tim = 0; for (int i = 1; i <= 10; i++) sol[i] = 0;}
    void input(int opt=1)
    {
        num = tim = 0;
        for (int t, i = 1; i <= 10; i++)
        {
            t = read();
            if (~t)
            {
                x[i] = t;
                y[i] = read();
                sol[++num] = x[i];
                tim += t + y[i] * 20;
                if (opt)
                {
                    pmi[i] = min(pmi[i], x[i]);
                    mx = max(mx, x[i]);
                    mi = min(mi, x[i]);
                }
            }
        }
        sort(sol + 1, sol + num + 1, greater<int>());
    }
    bool operator <(const Data &t) const
    {
        if (num == t.num)
        {
            if (tim == t.tim)
            {
                for (int i = 1; i <= num; i++)
                    if (sol[i] != t.sol[i])
                        return sol[i] < t.sol[i];
                return id > t.id;
            }
            return tim < t.tim;
        }
        return num > t.num;
    }
}a[N], f, g;

int n, ans, r1, r2, r3, p[15];
int getrk()
{
    int l = 1, r = n - 1, ret = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (!(g < a[mid])) //0000000001111找第一个0的位置+1,0是严格小于
        {
            l = mid + 1;
            ret = mid;
        }
        else r = mid - 1;
    }
    return ret + 1;
}

int main()
{
    memset(pmi, 0x3f, sizeof(pmi));
    scanf("%d", &n);
    r1 = n / 10; //向下取整
    r2 = 3 * n / 10;
    r3 = 6 * n / 10;

    for (int i = 1; i < n; i++)
        a[i].input();
    sort(a + 1, a + n);
    f.input(0);
    int nf = 0;
    for (int i = 1; i <= 10; i++)
        if (f.x[i]) p[++nf] = i;
    do
    {
        int num = 0, tim = 0, sol[15], ct = 0;
        int cur = 0; g.init();
        for (int u, i = 1; i <= nf; i++)
        {
            u = p[i];
            ct += f.x[u];
            if (ct > 300) {ct -= f.x[u]; break;}
            tim += ct + f.y[u] * 20;
            sol[++num] = ct;

            if (ct <= pmi[u])
                cur += 800; //每题的一血，可以取等
            if (num == 1 && ct <= mi)
                cur += 700; //全场一血
        }
        if (ct >= mx && num) cur += 500; //顽强拼搏
        g.num = num; g.tim = tim; g.id = 50;
        for (int i = 1; i <= num; i++)
            g.sol[i] = sol[num - i + 1];
        
        int r = getrk();
        cur += 5000 / r;
        if (r <= r1) cur += 1200;
        else if (r <= r2) cur += 800;
        else if (r <= r3) cur += 400;
        ans = max(ans, cur);
    }while(next_permutation(p + 1, p + nf + 1));
    printf("%d\n", ans);
    return 0;
}