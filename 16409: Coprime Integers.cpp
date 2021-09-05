#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define PER(i,a,b) for (auto i = (b); i >= (a); --i)
#define log2(x) (31-__builtin_clz(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (int)(x).size()
#define PB push_back
#define FI first
#define SE second
#define mup(x,y) x = min(x,y)
#define Mup(x,y) x = max(x,y)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long; using ii = pair<int,int>; using iii = tuple<int,int,int>;
void solution(); int main() {ios::sync_with_stdio(0); cin.tie(0); solution();}

struct PrecalcMultiFunc {
    int B; //boundary
    vector<int> lpf, prime, mobius, totient; // number of multiples
    PrecalcMultiFunc(int B): B(B), lpf(B+1), mobius(B+1), totient(B+1) { // O(B)
        lpf[0] = lpf[1] = -1;
        mobius[1] = totient[1] = 1;
        REP(x,2,B) {
            if (!lpf[x]) prime.push_back(x), mobius[x] = -1, totient[1] = 1;
            for (auto p : prime) {
                if (x*p > B) break;
                lpf[x*p] = p;
                if (x%p == 0) {
                    mobius[x*p] = 0, totient[x*p] = totient[x]*p;
                    break;
                }
                mobius[x*p] = mobius[x]*mobius[p];
                totient[x*p] = totient[x]*totient[p];
            }
        }
    }
    bool is_prime(ll n) const {
        // O(1) when n<=B
        // O(n/log(n)) when B<n<=B²
        // O(√n) when n>B²
        if (n <= B) return lpf[n] == n;
        if (n <= B*B) {
            for (int p : prime)
                if (n%p == 0) return false;
            return true;
        }
        for (ll p = 2; p*p <= n; ++p)
            if (n%p == 0) return false;
        return true;
    }
    int mobius_large(ll n) const {
        // O(1) when n<=B
        // O(n/log(n)) when B<n<=B²
        // O(√n) when n>B²
        if (n <= B) return mobius[n];
        int res = 1;
        if (n <= B*B) {
            for (int p : prime) {
                if (n%p == 0) {
                    if (n/p%p == 0) return 0;
                    n /= p, res = -res;
                }
            }
            if (n > 1) return -res;
            return res;
        }
        for (ll p = 2; p*p <= n; ++p) {
            if (n%p == 0) {
                if (n/p%p == 0) return 0;
                n /= p, res = -res; //제곱인수 있으면 이미 걸러져서 1번만 나눠도 충분
            }
        }
        if (n > 1) return -res;
        return res;
    }
    ll totient_large(ll n) const {
        // O(1) when n<=B
        // O(n/log(n)) when B<n<=B²
        // O(√n) when n>B²
        if (n <= B) return totient[n];
        ll res = n;
        if (n <= B*B) {
            for (int p : prime) {
                if (n%p == 0) {
                    while (n%p == 0) n /= p;
                    res -= res/p;
                }
            }
            if (n > 1) return res-res/n;
            return res;
        }
        for (ll p = 2; p*p <= n; ++p) {
            if (n%p == 0) {
                while (n%p == 0) n /= p;
                res -= res/p;
            }
        }
        if (n > 1) return res-res/n;
        return res;
    }
    vector<ll> factors_large(ll n) const {
        // O(log n) when n<=B
        // O(n/log(n)) when B<n<=B²
        // O(√n) when n>B²
        vector<ll> f;
        if (n <= B) {
            while (lpf[n] > 0) f.push_back(lpf[n]), n /= lpf[n];
            return f;
        }
        if (n <= B*B) {
            for (int p : prime)
                while (n%p == 0) f.push_back(p), n /= p;
            if (n > 1) f.push_back(n);
            return f;
        }
        for (ll p = 2; p*p <= n; ++p)
            while (n%p == 0) f.push_back(p), n /= p;
        if (n > 1) f.push_back(n);
        return f;
    }
};

void solution() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    PrecalcMultiFunc pre(10000000);
    auto mu = pre.mobius;
    ll ans = 0;
    REP(m,1,min(b,d)) {
        ans += ll(mu[m])*(b/m-(a-1)/m)*(d/m-(c-1)/m);
    }
    cout << ans;
}
