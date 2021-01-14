#include <iostream>
using namespace std;
int dp[1001][1001];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            char c; cin >> c;
            dp[i][j] = c-48;
        }
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= m; ++j) {
            if (dp[i][j]) dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
        }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ans = max(dp[i][j], ans);
    cout << ans*ans;
}
