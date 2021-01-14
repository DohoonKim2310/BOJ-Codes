#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
    int N; cin >> N;
    ld S = 0;
    complex<ld> p[N+1];
    for (int i = 0; i < N; ++i) {ld x, y; cin >> x >> y; p[i] = {x, y};}
    p[N] = p[0];
    for (int i = 0; i < N; ++i)
        S += (conj(p[i])*p[i+1]).imag();
    S /= 2;
    cout << fixed; cout.precision(1);
    cout << abs(S);
}
