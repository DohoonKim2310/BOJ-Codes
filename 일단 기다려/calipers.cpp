#include <bits/stdc++.h>
using namespace std; using ii = pair<int,int>;
using ll = long long; using ld = long double;
#define _(x) const x&
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define ZIP(x) (x).erase(unique((x).begin(),(x).end()),(x).end())
#define MP make_pair
#define mup(x,y) x = min(x,y)
#define Mup(x,y) x = max(x,y)
#define size(x) int((x).size())
#pragma region Geometry
using P = complex<ll>; using Poly = vector<P>;
constexpr ld PI = acos(-1.0L), TAU = 2*PI;
#define X real()
#define Y imag()
#define dot(u,v) (conj(u)*(v)).X
#define cross(u,v) (conj(u)*(v)).Y
#define norm(u) dot(u,u)
int ccw(P a, P b, P c) {
    auto v = cross(b-a,c-b);
    if (v < 0) return -1;
    else if (v > 0) return 1;
    return 0;
}
ld abs(P u) {return sqrt(ld(norm(u)));}
istream &operator >> (istream &is, P &p) {ll x, y; is >> x >> y; p = {x,y}; return is;}
namespace std { bool operator < (P u, P v) {return u.X == v.X ? u.Y < v.Y : u.X < v.X;} }
#pragma endregion

pair<Poly,Poly> convex_hull(vector<P> &p) {
    sort(p.begin(),p.end());
    Poly up(size(p)), lo(size(p));
    int u = 0, l = 0, i = 0, j = size(p)-1;
    REP(_,1,size(p)) {
        while (u >= 2 and ccw(up[u-2],up[u-1],p[i]) >= 0) --u;
        while (l >= 2 and ccw(lo[l-2],lo[l-1],p[j]) >= 0) --l;
        up[u++] = p[i++], lo[l++] = p[j--];
    }
    up.resize(u), lo.resize(l);
    return {up,lo};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<P> points(n); for (auto &p : points) cin >> p;
    auto [u,l] = convex_hull(points);
    ll dsq = 0;
    int a = 0, b = 0;
    while (a+1 < size(u) or b+1 < size(l)) {
        Mup(dsq,norm(u[a]-l[b]));
        if (a+1 == size(u)) ++b;
        else if (b+1 == size(l)) ++a;
        else if (ccw(u[a+1]-u[a],{0,0},l[b+1]-l[b]) < 0) ++a;
        else ++b;
    }
    cout << dsq;
}