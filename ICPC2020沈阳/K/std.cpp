#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("test.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int s1 = 0, s2 = 0;
    vector<int>v1, v2;
    for (int i = 1; i <= n; ++i) {
        char c; int x;
        cin >> c >> x;
        if (c == '+') s1++, v1.push_back(x);
        else s2++, v2.push_back(x);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    long long ans = 0;
    for (int i = 0; i < s1; ++i) {
        ans += lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
    }
    cout<<ans<<endl;
    double tmp = 1.0 * ans / s1 / s2;
    cout << fixed << setprecision(10) << tmp;
}