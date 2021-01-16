#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int N = 10001;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a[N], b[N], from[N]; cin >> n;
    for (int i = 1; i <= n; ++i) {int x; cin >> x; a[x] = i;}
    for (int i = 1; i <= n; ++i) cin >> b[i];
    int dp[N] = {0,};
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[b[i]] > a[b[j]] && dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    from[i] = j;
            }
        }
    }
    cout << *max_element(dp+1, dp+n+1) << '\n';
    int x = max_element(dp+1, dp+n+1)-dp;
    set<int> ans;
    while (x) {
        ans.emplace(b[x]);
        x = from[x];
    }
    for (auto p : ans) cout << p << ' ';
    return 0;
}
