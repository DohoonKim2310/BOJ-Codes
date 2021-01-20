#include <iostream>
using namespace std;
using ll = long long;
ll a, p;

int dnc(ll n) {
    if (n == 1) return a;
    ll tmp = dnc(n/2);
    if (n&1) return (((tmp*tmp)%p)*a)%p;
    return (tmp*tmp)%p;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int x = 2; x*x <= n; ++x)
        if (n%x == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> p;
    while (a|p) {
        a %= p;
        cout << ((!isPrime(p) && a == dnc(p)) ? "yes" : "no") << '\n';
        cin >> p >> a;
    }
    return 0;
}
