#include <iostream>
#include <algorithm>
using namespace std;
#define REP(i,n) for (int i = 0; i < n; ++i)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int A[n], B[n], C[n], D[n], CD[n*n];
    REP(i, n) cin >> A[i] >> B[i] >> C[i] >> D[i];
    REP(i, n) REP(j, n) CD[i*n+j] = C[i]+D[j];
    sort(CD, CD+n*n);
    long long ans = 0;
    REP(i, n) REP(j, n) {
        auto it = lower_bound(CD, CD+n*n, -A[i]-B[j]);
        if (it == CD + n*n || *it != -A[i]-B[j]) continue;
        ans += upper_bound(CD, CD+n*n, -A[i]-B[j])-it;
    }
    cout << ans;
    return 0;
}
