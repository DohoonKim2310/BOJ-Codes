#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define PER(i,a,b) for (auto i = (b); i >= (a); --i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;
const int N = 503, MOD = 1e9+7;
int n; ll dp[2][N][N];
char farm[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    REP(i,1,n) {
        REP(j,1,n) cin >> farm[j][i];
        dp[1][i][i] = 1;
    }
    REP(len,2,n) {
        auto now = dp[len&1], pre = dp[(len-1)&1];
        REP(sx,1,n) PER(ex,sx,n) {
            int sy = n+2-len-sx, ey = n+len-ex;
            if (sy < 1 or sy > n or ey > n or ey < 1 or sy > ey) continue;
            if (farm[sx][sy] != farm[ex][ey]) continue;
            now[sx][ex] = pre[sx+1][ex-1]+pre[sx+1][ex]+pre[sx][ex-1]+pre[sx][ex];
            now[sx][ex] %= MOD;
        }
        fill(pre[1],pre[n+1],0);
    }
    cout << dp[n&1][1][n];
}
