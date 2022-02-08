#include "CPheader.hpp"
const int N = 1001;
pi p[N], from[N][N];
int m[N][N], n, w, ans[N];
bool ready[N][N];

void tracking(int idx, pi t) {
    if (t == make_pair(0,0)) return;
    pi before = from[t.F][t.S];
    if (t.F == idx) while (idx > t.S) ans[idx--] = 1;
    else while (idx > t.F) ans[idx--] = 2;
    tracking(idx, before);
    return;
}

inline int dist(int a, int b, bool c) {
    if (b == 0) return c ? abs(p[a].F-n)+abs(p[a].S-n) : p[a].F+p[a].S-2;
    return abs(p[a].F-p[b].F)+abs(p[a].S-p[b].S);
}

int dp(int x, int y) {
    if (ready[x][y]) return m[x][y];
    assert(x != y);
    ready[x][y] = true;
    m[x][y] = INF;
    if (x > y) {
        if (x == y+1) REP0(k,y) {
            if (m[x][y] > dp(k,y)+dist(x,k,0)) {
                m[x][y] = dp(k,y)+dist(x,k,0);
                from[x][y] = {k,y};
            }
        } else {
            m[x][y] = dp(x-1,y)+dist(x,x-1,0);
            from[x][y] = {x-1,y};
        }
    } else {
        if (y == x+1) REP0(k,x) {
            if (m[x][y] > dp(x,k)+dist(y,k,1)) {
                m[x][y] = dp(x,k)+dist(y,k,1);
                from[x][y] = {x,k};
            }
        } else {
            m[x][y] = dp(x,y-1)+dist(y,y-1,1);
            from[x][y] = {x,y-1};
        }
    }
    return m[x][y];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w;
    REP1(i,w) cin >> p[i].F >> p[i].S;
    m[0][0] = 0; ready[0][0] = true;
    m[1][0] = dist(1,0,0); ready[1][0] = true;
    m[0][1] = dist(1,0,1); ready[0][1] = true;
    //print
    int mn = INF;
    pi endpoint;
    REP0(i,w) {
        if (mn > dp(w,i)) {
            mn = dp(w,i);
            endpoint = {w,i};
        }
        if (mn > dp(i,w)) {
            mn = dp(i,w);
            endpoint = {i,w};
        }
    }
    cout << mn << endl;
    tracking(w, endpoint);
    REP1(i,w) cout << ans[i] << endl;
    return 0;
}
