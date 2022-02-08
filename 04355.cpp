#include <iostream>
#include <cmath>
using namespace std;

int phi(int x) {
    int ans = 1;
    for (long long p = 2; p <= x; ++p) if (!(x%p)) {
        int tmp = 1;
        while (x%p == 0) {
            x /= p;
            tmp *= p;
        }
        ans *= tmp/p*(p-1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (1) {
        int n; cin >> n;
        if (!n) break;
        cout << phi(n) << '\n';
    }
    return 0;
}
