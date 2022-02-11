#include <bits/stdc++.h>
using namespace std; using ii = pair<int,int>;
using ll = long long; using ld = long double;
#define _(x) const x&
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define ZIP(x) (x).erase(unique((x).begin(),(x).end()),(x).end())
#define MP make_pair
#define mup(x,y) x = min(x,y)
#define Mup(x,y) x = max(x,y)
#define size(x) int((x).size())

const int N = 103, MOD = 1e9;
int n;
ll dp[N][10], cant_go[N][10][3];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    if (n < 10) cout << 0;
    else {
        REP(d,0,9) dp[1][d] = 1;
        REP(d,1,8) cant_go[1][d][0] = cant_go[1][d][1] = cant_go[1][d][2] = 1;
        cant_go[1][0][2] = cant_go[1][9][1] = 1;
        REP(l,1,n) REP(d,0,9) {
            if (d > 1) cant_go[l][d][1] += cant_go[l-1][d-1][1],
                       cant_go[l][d][0] += cant_go[l-1][d-1][0];
            if (d < 9) cant_go[l][d][1] += cant_go[l-1][d+1][1];
            if (d < 8) cant_go[l][d][2] += cant_go[l-1][d+1][2],
                       cant_go[l][d][0] += cant_go[l-1][d+1][0];
            if (d > 0) cant_go[l][d][2] += cant_go[l-1][d-1][2];
            cant_go[l][d][0] %= MOD;
            cant_go[l][d][1] %= MOD;
            cant_go[l][d][2] %= MOD;
        }
        REP(l,2,n) REP(d,0,9) {
            if (d > 0) dp[l][d] += dp[l-1][d-1];
            if (d < 9) dp[l][d] += dp[l-1][d+1];
            dp[l][d] %= MOD;
        }
        ll answer = 0;
        REP(d,1,9) {
            answer += dp[n][d]-cant_go[n][d][1]-cant_go[n][d][2]+cant_go[n][d][0];
            answer %= MOD;
        }
        cout << (answer+MOD)%MOD;
    }
}
