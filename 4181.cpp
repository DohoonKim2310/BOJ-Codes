#include <bits/stdc++.h>
#define X real()
#define Y imag()
#define cross(u, v) (conj(u)*(v)).Y
using namespace std;
using C = long long;
using P = complex<C>;
using poly = vector<P>;

bool cmp(const P& a, const P& b) {
    if (a.X == b.X) return a.Y < b.Y;
    return a.X < b.X;
}

bool isCcw(const poly& hull, const P& p) {
    return cross(hull.back()-*(hull.end()-2), p-hull.back()) > 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    poly p, uphull, lohull;
    for (int i = 0; i < n; ++i) {
        int x, y; char c; cin >> x >> y >> c;
        if (c == 'Y') p.push_back({x, y});
    }
    sort(begin(p), end(p), cmp);
    
    for (int i = 0; i < p.size(); ++i) {
        while (size(uphull) >= 2 && isCcw(uphull, p[i])) uphull.pop_back();
        uphull.push_back(p[i]);
    } uphull.pop_back();
    
    for (int i = (int)size(p)-1; i >= 0; --i) {
        while (size(lohull) >= 2 && isCcw(lohull, p[i])) lohull.pop_back();
        lohull.push_back(p[i]);
    }
    
    cout << size(lohull)+size(uphull)-1 << '\n';
    
    for (int i = (int)size(lohull)-1; i >= 0; --i)
        cout << lohull[i].X << ' ' << lohull[i].Y << '\n';
    
    for (int i = (int)size(uphull)-1; i > 0; --i)
        cout << uphull[i].X << ' ' << uphull[i].Y << '\n';
}
