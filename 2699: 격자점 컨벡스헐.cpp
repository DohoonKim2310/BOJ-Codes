#include <bits/stdc++.h>
#define X real()
#define Y imag()
#define PB push_back
#define cross(u, v) (conj(u)*(v)).Y
using namespace std;
using C = long long;
using P = complex<C>;
using poly = vector<P>;

bool cmp(const P& a, const P& b) {
    if (a.Y == b.Y) return a.X < b.X;
    return a.Y > b.Y;
}

bool isHullCcw(const poly& hull, const P& p) {
    if (hull.size() < 2) return false;
    return cross(hull.back()-*(hull.end()-2), p-hull.back()) >= 0;
}

int main() {
	int t; cin >> t;
	while (t--) {
    	int n; cin >> n;
		P p[n];
    	for (auto& s: p) {
    	    int x, y; cin >> x >> y;
    	    s = {x, y};
    	}
    	sort(p, p+n, cmp);
		poly h1, h2;
    	h1.PB(p[0]); h1.PB(p[1]);
    	for (int i = 2; i < n; ++i) {
    	    while (isHullCcw(h1, p[i])) h1.pop_back();
    	    h1.PB(p[i]);
    	} h1.pop_back();
    	h2.PB(p[n-1]); h2.PB(p[n-2]);
    	for (int i = n-3; i >= 0; --i) {
    	    while (isHullCcw(h2, p[i])) h2.pop_back();
    	    h2.PB(p[i]);
    	} h2.pop_back();
		cout << h1.size()+h2.size() << '\n';
		for (auto p: h1) printf("%lld %lld\n", p.X, p.Y);
		for (auto p: h2) printf("%lld %lld\n", p.X, p.Y);
	}
}
