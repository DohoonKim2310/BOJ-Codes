#pragma region Code by hgmhc
// g++-11 -std=c++17 -O2 -Wall -Wno-unknown-pragmas -DLOCAL
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define PER(i,a,b) for (auto i = (b); i >= (a); --i)
#define SIZE(x) (int)(x).size()
int lg(int x) { assert(x > 0); return 31-__builtin_clz(x); }
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define ALL(x) (x).begin(), (x).end()
#define mup(x,y) x = min(x,y)
#define Mup(x,y) x = max(x,y)
#define F first
#define S second
#define INC(a,b,c) ((a) <= (b) && (b) <= (c))
#define SQU(x) ((x)*(x))
string to_string(string s) { return '"'+s+'"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <typename A,typename B>
string to_string(pair<A,B> p) { return "("+to_string(p.F)+","+to_string(p.S)+")"; }
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out() { cerr << endl; }
template <typename Head,typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
#ifdef LOCAL
#define el endl
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define el '\n'
#define debug(...)
#endif
void solution(); int main() {cin.tie(0)->sync_with_stdio(0); solution();}
#pragma endregion

const int N = 53, L = 10003;
int n, l, rad[N];

const ll MOD = 1e9+7, P = MOD;
namespace modulo {
    #define Add(x,y) x = add(x,y)
    #define Sub(x,y) x = sub(x,y)
    #define Mul(x,y) x = mul(x,y)
    #define Mod(x) x = mod(x)
    ll add(ll x, ll y) { x += y; return x >= MOD ? x-MOD : x; }
    ll sub(ll x, ll y) { x -= y; return x < 0 ? x+MOD : x; }
    ll mul() { return 1; }
    template <typename... Lls>
    ll mul(ll num, Lls... nums) { return (mul(nums...)*num)%MOD; }
    template <typename T>
    ll modpow(ll x, T e) {
        ll ans = 1;
        for(; e; e >>= 1, x = mul(x,x)) if (e&1)
            ans = mul(ans,x);
        return ans;
    }
    ll mod(ll x) { x %= MOD; return x < 0 ? x+MOD : x;}
    ll inv(ll x) { return modpow(x,P-2); }
}

template <const int N>
struct Combination {
    ll fac[N+1], ifac[N+1];
    Combination() {
        fac[0] = ifac[0] = 1;
        REP(i,1,N) fac[i] = modulo::mul(fac[i-1],i);
        ifac[N] = modulo::inv(fac[N]);
        for (int i = N-1; i; --i)
            ifac[i] = modulo::mul(i+1,ifac[i+1]);
    }
};
Combination<L> _cb;
ll C(int n, int k) {
    if (k < 0 or n < k) return 0;
    return modulo::mod(modulo::mul(_cb.fac[n],_cb.ifac[k],_cb.ifac[n-k]));
}

int r;

void input() {
    cin >> n >> l;
    REP(i,1,n) cin >> rad[i];
    r = rad[1];
}
void solution() {
    input();
    if (n <= 10) {
        ll ans = 0;
        vector<int> p(n); iota(ALL(p),1);
        do {
            ll fixed = 0;
            REP(i,1,n-1) {
                fixed += max(rad[p[i-1]]-1,rad[p[i]]-1);
            }
            ans = modulo::add(ans,C(l-fixed,n));
        } while (next_permutation(ALL(p)));
        cout << ans;
    } else if (n <= 30 and l <= 300) {
        
    } else {
        int fixed = (r-1)*(n-1);
        cout << modulo::mul(C(l-fixed,n),_cb.fac[n]);
    }
}
