#include <bits/stdc++.h>
#define X real()
#define Y imag()
#define cross(u, v) (conj(u)*(v)).Y
#define ok(h, p) size(h) >= 2 ? cross(h.back()-*(end(h)-2), p-h.back()) >= 0 : false
using namespace std;
using G = long double; using P = complex<G>; using poly = vector<P>;
const G TAU = 6.283185;

G ang(const P& u, const P& v) {
    G a = abs(arg(u)-arg(v));
    return min(TAU-a, a);
}

bool cmp(const P& a, const P& b) {
    if (a.X == b.X) return a.Y < b.Y;
    return a.X < b.X;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed; cout.precision(6);
    int n; cin >> n;
    G ret = 0;
    P p[n], c {0, 1};
    poly up, lo;
    for (auto& s: p) {
        G x, y; cin >> x >> y;
        s = {x, y};
    }
    //make convex hull
    sort(p, p+n, cmp);
    for (int i = 0; i < n; ++i) {
        while (ok(up, p[i])) up.pop_back();
        while (ok(lo, p[n-1-i])) lo.pop_back();
        up.emplace_back(p[i]); lo.emplace_back(p[n-1-i]);
    }
    //rotating calipers
    int L = size(lo)-1, R = size(up)-1;
    if (L+R == 2) cout << abs(up[0]-lo[0]);
    else {
       for (int a = 0, b = 0; a < R || b < L;) {
           if (ang(c, up[a+1]-up[a]) > ang(-c, lo[b+1]-lo[b])) {c = -lo[b+1]+lo[b]; ++b;}
           else {c = up[a+1]-up[a]; ++a;}
           ret = max(ret, abs(up[a]-lo[b]));
        }
       cout << ret;
    }
    return 0;
}
