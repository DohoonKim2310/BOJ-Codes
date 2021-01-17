#include <iostream>
#include <vector>
typedef long long ll;
#define REP(i,b) for (int i = 0; i < b; ++i)
using namespace std;
using Mat = vector<vector<ll>>;
const int MOD = 1000;
int n;
Mat M;

Mat operator * (const Mat& a, const Mat& b) {
    Mat ans(n, vector<ll>(n, 0));
    REP(i,n) REP(j,n) REP(k,n)
        ans[i][j] = (ans[i][j]+a[i][k]*b[k][j])%MOD;
    return ans;
}

Mat powmat(ll x) {
    if (x == 1) return M;
    Mat tmp = powmat(x/2);
    if (x%2) return tmp*tmp*M;
    return tmp*tmp;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll b;
    cin >> n >> b;
    M.assign(n, vector<ll>(n,0));
    REP(i,n) REP(j,n) cin >> M[i][j];
    Mat ans = powmat(b);
    REP(i,n) REP(j,n) cout << ans[i][j]%MOD << " \n"[j == n-1];
    return 0;
}
