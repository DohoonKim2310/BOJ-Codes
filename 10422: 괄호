#include <iostream>
using namespace std;
using ll = long long;
const ll p = 1e9+7, N = 5004;
ll memo[N][N];

ll c(ll n, ll r) {
    if (n == r || r == 0) return 1LL;
    if (memo[n][r]) return memo[n][r];
    return memo[n][r] = (c(n-1,r-1)+c(n-1,r))%p;
}

ll modpow(const ll& a, ll x) {
    if (x == 0) return 1LL;
    ll tmp = modpow(a,x/2);
    tmp = (tmp*tmp)%p;
    if (x&1LL) return (tmp*a)%p;
    return int(tmp);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll x; cin >> x;
        if (x&1) cout << 0 << '\n';
        else cout << (c(x,x/2)*modpow(x/2+1,p-2)+p)%p << '\n';
    }
    return 0;
}
