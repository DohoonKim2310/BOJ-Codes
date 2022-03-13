#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
using namespace std;

const int N = 13, M = 223;
int n, m, s, x = 1, dp[N][M];

void dfs(int i, int j) {
    if (i == 0) return;
    for (int k = j; k >= 0; k -= i, ++x) {
        if (s <= dp[i-1][k]) {
            cout << x << ' ';
            dfs(i-1,k);
            return;
        }
        s -= dp[i-1][j];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s;
    dp[0][0] = 1;
    REP(i,1,n) REP(j,0,m-n) {
        for (int k = j; k >= 0; k -= i)
            dp[i][j] += dp[i-1][k];
    }
    dfs(n,m-n);
}
