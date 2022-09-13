#include <bits/stdc++.h>
using namespace std; using ii = pair<int,int>; using ll = long long;
void o_o(){ cerr << endl; }
template <class H, class...T> void o_o(H h,T...t) { cerr << ' ' << h; o_o(t...); }
#define debug(...) cerr<<'['<<#__VA_ARGS__<<"]:",o_o(__VA_ARGS__)
#define rep(i,a,b) for (auto i = (a); i <= (b); ++i)
#define all(x) (x).begin(), (x).end()
#define size(x) int((x).size())
#define fi first
#define se second

const int N = 3003;
int n;
pair<ii,int> p[N];
ll w[N][N];

template <cosnt int N> struct fenwick_tree {
    ll t[N+1];
    void add(int k, ll v) {
        for (++k; k <= N; k += k&-k) t[k] += v;
    }
    ll sum(int a, int b) {
        ll s = 0;
        for (++b; b >= 1; b -= b&-b) s += t[b];
        for (; a >= 1; a -= a&-a) s -= t[a];
        return s;
    }
};

void subtask1() {
    static ll pfx[N][N] {0,};
    ll answer = -1e18;
    rep(i,1,n) rep(j,1,n) {
        pfx[i][j] = pfx[i-1][j]+pfx[i][j-1]-pfx[i-1][j-1]+w[i][j];
    }
    rep(i,1,n) rep(j,1,n) rep(ii,i,n) rep(jj,j,n) {
        answer = max(answer, pfx[ii][jj] - pfx[ii][j-1] - pfx[i-1][jj] + pfx[i-1][j-1]);
    }
    cout << answer;
}
void subtask2() {
}
void subtask3() {
}
void subtask4() {
    ll best = -1e18, sum = 0;
    rep(i,1,n) {
        sum = max(sum+w[i][1],w[i][1]);
        best = max(best,sum);
    }
    cout << best;
}
void fulltask() {
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int c = 0, d = 1;
    vector<int> xs, ys;
    rep(i,1,n) {
        cin >> p[i].fi.fi >> p[i].fi.se >> p[i].se;
        xs.push_back(p[i].fi.fi);
        ys.push_back(p[i].fi.se);
        if (p[i].se < 0) c++;
        if (p[i].fi.se != 0) d = 0;
    }
    sort(all(xs)), xs.erase(unique(all(xs)),end(xs));
    sort(all(ys)), ys.erase(unique(all(ys)),end(ys));
    rep(i,1,n) {
        p[i].fi.fi = lower_bound(all(xs),p[i].fi.fi)-begin(xs)+1;
        p[i].fi.se = lower_bound(all(ys),p[i].fi.se)-begin(ys)+1;
        w[p[i].fi.fi][p[i].fi.se] = p[i].se;
    }
    if (d) subtask4();
    else if (n <= 100) {
        subtask1();
    } else if (n <= 500) {
        subtask2();
    } else if (c == 1) {
        subtask3();
    } else {
        fulltask();
    }
}