#include <iostream>
#include <string>
#define REP(i,a,b) for (int i = a; i <= b; ++i)
using namespace std;
const int N = 1001;
int dp[N][N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string a, b; cin >> a >> b;
    REP(i,0,size(a)) dp[i][0] = i; REP(i,0,size(b)) dp[0][i] = i;
    REP(i,1,size(a)) REP(j,1,size(b))
        dp[i][j] = min(dp[i-1][j-1]+(a[i-1]!=b[j-1]),min(dp[i-1][j],dp[i][j-1])+1);
    cout << dp[size(a)][size(b)];
    return 0;
}
