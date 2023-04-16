#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50, M = 26;
typedef long long ll;
int n, cnt[M];
ll t, bin[M] = {1};
char s[N];
int main()
{
    for (int i = 1; i < M; i++)
        bin[i] = bin[i - 1] << 1;
    scanf("%d%lld%s", &n, &t, s + 1);
    for (int i = 1; i <= n - 2; i++)
        ++cnt[s[i] - 'a'];
    ll x = 0; // max val
    for (int i = 0; i < M; i++)
        x += 1ll * cnt[i] * bin[i];
    x += bin[s[n] - 'a'] - bin[s[n - 1] - 'a'];
    ll del = x - t;
    if (del < 0) return 0 * puts("No");
    //cout<<"del:"<<del<<endl;
    int top = 25;
    while (top >= 0 && del > 0)
    {
        while (cnt[top] && del >= 2 * bin[top])
        {
            //cout<<"top: "<<top<<" cnt:"<<cnt[top]<<endl;
            del -= 2 *bin[top];
            --cnt[top];
        }
        --top;
    }
    puts(del == 0 ? "Yes" : "No");
    return 0;
}