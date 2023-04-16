#include <bits/stdc++.h>

#define mp make_pair
#define pa pair <int, int>

using namespace std;
const int N = 1e6+50;
char s[N];
 
int sa[N], rk[N], tmp[N], t[N], n, m, k;
void getsa()
{
    m='z';
    memset(t,0,sizeof(int)*(m+1));
    for (int i=1;i<=n;i++) ++t[rk[i]=s[i]];
    for (int i=1;i<=m;i++) t[i]+=t[i-1];
    for (int i=n;i>=1;i--) sa[t[rk[i]]--]=i;
     
    for (int cnt,k=1;;k<<=1)
    {
        cnt=0;
        for (int i=n-k+1;i<=n;i++) tmp[++cnt]=i;
        for (int i=1;i<=n;i++)
            if (sa[i]>k) tmp[++cnt]=sa[i]-k;
        memset(t,0,sizeof(int)*(m+1));
        for (int i=1;i<=n;i++) ++t[rk[tmp[i]]];
        for (int i=1;i<=m;i++) t[i]+=t[i-1];
        for (int i=n;i>=1;i--) sa[t[rk[tmp[i]]]--]=tmp[i];
        swap(tmp,rk); rk[sa[1]]=cnt=1;
        for (int i=2;i<=n;i++)
            rk[sa[i]]=( tmp[sa[i]]==tmp[sa[i-1]] && tmp[sa[i]+k]==tmp[sa[i-1]+k] ? cnt : ++cnt);
        if ((m=cnt)>=n) break;
    }
}
 
int pos, prepos, top; //之前最大的字母位置prepos
char ans[N]; //总答案
 
int ct;
int wo[N], wt;
 
pa getlen(int x, int y)
{
    while (x <= y && wo[x] <= pos) ++x;
    if (x > y) return mp(0, 0);
    int i = wo[x], ret = 1;
    while (i < n && s[i + 1] == s[i])
        ++i, ++ret;
    return mp(ret, i);
}
int q[N], qt;
void work(int x, int y) //sa数组的处理范围(x, y) 在这范围内s[sa[i]]相同
{
    ct = 0;
    while (pos < n && s[pos + 1] == s[wo[y]]) //和上一个位置连在一起，不用删，直接放入答案
        ++ct,++pos;
    int mx = 0, nxp;
    qt = 0;
    while (k && x <= y)
    {
        if (qt && (qt > mx || (qt == mx && rk[nxp - mx + 1] < rk[pos - mx + 1]))) //rk是从小到大的顺序,下一个后缀比当前的小
        {
            ct += qt;
            --q[qt];
            while (qt && q[qt] == 0) --qt;
            --k;
            continue;
        }
 
        while (x <= y && wo[x] <= pos) ++x;
        if (x > y) break;
 
        int l = pos;
        pos = wo[x]; // 下一个pos以后且不相连的最大位置一定为答案
        int r = pos;
        ++ct;
        --k; ++x; //消耗一次删除次数
        while (s[pos + 1] == s[wo[y]]) //和上一个位置连在一起，不用删，直接放入答案
            ++ct,++pos;
 
        int cnt = 0; //两段之间有多少个最大字母段，丢到答案里
        for (int i = l + 1; i < r; i++) //两段之间有多少个最大字母段，丢到答案里
        {
            if (s[i] == s[wo[y]]) ++cnt;
            else if (cnt) {++q[cnt]; qt = max(qt, cnt); cnt = 0;}
        }
        if (cnt) {++q[cnt]; qt = max(qt, cnt); cnt = 0;} //两段之间有多少个最大字母段，丢到答案里
        if (pos != n && qt)
        {
            pa tp = getlen(x, y);
            mx = tp.first, nxp = tp.second;
        }
    }
    while (k && qt)
    {
        --k;
        ct += qt;
        --q[qt];
        while (qt && q[qt] == 0) --qt;
    }
}
void init()
{
    for (int i = 0; i <= n; i++)
        rk[i] = sa[i] = tmp[i] = q[i] = 0;
}
int main()
{
    int T, ysk;
    // scanf("%d", &T);
    // while (T--)
    {
        init();
        scanf("%s",s+1);
        n = strlen(s + 1);
        for (int i = 1; i <= n; i++)
            s[i] = '9' - s[i] + '0';
        scanf("%d", &k);
        ysk = k;
        
        getsa();
        reverse(sa + 1, sa + n + 1);
        int l = 1, r = 1;
        pos = 0; top = ct = 0;
        prepos = 0;
        while (r <= n)
        {
            wt = 0;
            if (sa[r] > prepos) wo[++wt] = sa[r];
            while (r < n && s[sa[r + 1]] == s[sa[l]])
            {
                ++r;
                if (sa[r] > prepos)
                    wo[++wt] = sa[r];
            }
            //printf("work: %d %d\n", l, r);
            if (wt >= 1)
            {
                work(1, wt);
                for (int i = 1; i <= ct; i++) //work里的答案加到ans里
                    ans[++top] = s[wo[1]];
                if (k == 0) // 在这个字母段截止，那pos之后的全部加到答案里
                {
                    for (int i = pos + 1; i <= n; i++)
                        ans[++top] = s[i];
                    break;
                }
                prepos = pos; //之前最大的字母最后出现的位置
            }
            l = r = r + 1;
        }
        if (k) //全部递减了k还有剩余
        {
            int del = n - top; //删掉了这么多个字符
            if (ysk > del) //所有字母一个个删还不够
                top -= ysk - del;
        }

        for (int i = 1; i <= top; i++)
            ans[i] = '9' - ans[i] + '0';
        for (int i = 1; i <= top; i++)
            printf("%c", ans[i]);
        puts("");
    }
    return 0;
}