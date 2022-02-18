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

const int N = 5e5+3, M = 5e5+3;
int n, m;
vector<pair<int,ll>> adj[N];
bool visited[N];
bool color[N];
bool restored[N], can_restore;
int x;
ll a[N];

void dfs1(int s = 1, int c = 0, ll v = 0) {
    if (visited[s]) {
        if (color[s] != c) restored[s] = true, x = s, a[x] = v/2;
        return;
    }
    visited[s] = true;
    color[s] = c;
    for (auto [u,w] : adj[s]) {
        if (c) dfs1(u,!c,v-w);
        else dfs1(u,!c,v+w);
    }
}

void dfs2(int s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto [u,w] : adj[s]) {
        a[u] = w-a[s];
        dfs2(u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    REP(i,1,m) {
        int a, b, k;
        cin >> a >> b >> k;
        adj[a].push_back({b,k});
        adj[b].push_back({a,k});
    }
    REP(i,1,n) if (not visited[i]) dfs1(i);
    fill(visited,visited+N,0);
    REP(i,1,n) if (restored[i]) dfs1(i);
    fill(visited,visited+N,0);
    REP(i,1,n) if (restored[i]) dfs2(i);
    REP(i,1,n) can_restore |= visited[i];
    if (can_restore) REP(i,1,n) cout << a[i] << ' ';
    else cout << "ERROR";
}
