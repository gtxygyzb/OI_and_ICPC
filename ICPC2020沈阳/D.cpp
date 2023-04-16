#include <bits/stdc++.h>
using namespace std;
int ans, bin[50], n;
int count(int x)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        int r = 0;
        for (int j = i; j < n; j++)
        {
            if (x & bin[j]) ++r;
            if (r&1) ++ret;
        }
    }
    return ret;
}

string s[] = 
{
"bbbbrbbbb",
"bbbrbbbbr",
"bbbrbbbrr",
"bbbrbbrrb",
"bbbrbrrbb",
"bbbrrrbbb",
"bbrbbbbrb",
"bbrbbbrbr",
"bbrbbbrrr",
"bbrbbrbrb",
"bbrbbrrbr",
"bbrbbrrrr",
"bbrbrbrbb",
"bbrbrrbbr",
"bbrbrrbrr",
"bbrbrrrrb",
"bbrrbrbbb",
"bbrrrbbbr",
"bbrrrbbrr",
"bbrrrbrrb",
"bbrrrrrbb",
"brbbbbrbb",
"brbbbrbbr",
"brbbbrbrr",
"brbbbrrrb",
"brbbrbbrb",
"brbbrbrbr",
"brbbrbrrr",
"brbbrrbrb",
"brbbrrrbr",
"brbbrrrrr",
"brbrbbrbb",
"brbrbrbbr",
"brbrbrbrr",
"brbrbrrrb",
"brbrrbbrb",
"brbrrbrbr",
"brbrrbrrr",
"brbrrrbrb",
"brbrrrrbr",
"brbrrrrrr",
"brrbbrbbb",
"brrbrbbbr",
"brrbrbbrr",
"brrbrbrrb",
"brrbrrrbb",
"brrrbbbrb",
"brrrbbrbr",
"brrrbbrrr",
"brrrbrbrb",
"brrrbrrbr",
"brrrbrrrr",
"brrrrbrbb",
"brrrrrbbr",
"brrrrrbrr",
"brrrrrrrb",
"rbbbbrbbb",
"rbbbrbbbr",
"rbbbrbbrr",
"rbbbrbrrb",
"rbbbrrrbb",
"rbbrbbbrb",
"rbbrbbrbr",
"rbbrbbrrr",
"rbbrbrbrb",
"rbbrbrrbr",
"rbbrbrrrr",
"rbbrrbrbb",
"rbbrrrbbr",
"rbbrrrbrr",
"rbbrrrrrb",
"rbrbbbrbb",
"rbrbbrbbr",
"rbrbbrbrr",
"rbrbbrrrb",
"rbrbrbbrb",
"rbrbrbrbr",
"rbrbrbrrr",
"rbrbrrbrb",
"rbrbrrrbr",
"rbrbrrrrr",
"rbrrbbrbb",
"rbrrbrbbr",
"rbrrbrbrr",
"rbrrbrrrb",
"rbrrrbbrb",
"rbrrrbrbr",
"rbrrrbrrr",
"rbrrrrbrb",
"rbrrrrrbr",
"rbrrrrrrr",
"rrbbbrbbb",
"rrbbrbbbr",
"rrbbrbbrr",
"rrbbrbrrb",
"rrbbrrrbb",
"rrbrbbbrb",
"rrbrbbrbr",
"rrbrbbrrr",
"rrbrbrbrb",
};
int main()
{
    cin>>n;
    long long ans = 0, wn;
    if (n & 1) {ans += (n + 1) / 2; wn = n - 1;}
    else {wn = n;}
    wn /= 2;
    ans += 1LL * (wn + 1) * wn;
    cout<<ans<<endl;
    if (n <= 20)
    {
        bin[0] = 1;
        for (int i = 1; i <= n; i++)
            bin[i] = bin[i-1]<<1;
        int cnt = 0;
        for (int i = 0; i < bin[n]; i++)
            if (ans == count(i))
            {
                ++cnt;
                for (int j = n - 1; j >= 0; j--)
                    putchar(i & bin[j] ? 'r' : 'b');
                puts("");
                if (cnt == 100) break;
            }
    }
    /*else{
        for (int i = 0; i < 100; i++)
        {
            for (int j = 1; j <= n - 9; j++)
                putchar('b');
            cout<<s[i]<<endl;
        }
    }*/
    return 0;
}