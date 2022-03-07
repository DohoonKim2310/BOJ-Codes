#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
using namespace std; using ll = long long;

const int N = 1003, lgN = 13, K = 102;
const ll INF = 1e16;
int n, k, spt[N][lgN];
vector<pair<int,ll>> adj[N];
ll answer = INF, dep[N], lev[N];

int lca(int a, int b) {
    if (lev[a] < lev[b]) swap(a,b);
    REP(k,0,lgN-1) if ((lev[a]-lev[b])&(1<<k)) a = spt[a][k];
    if (a == b) return a;
    for (int k = lgN-1; k >= 0; --k)
        if (spt[a][k] != spt[b][k])
            a = spt[a][k], b = spt[b][k];
    return spt[a][0];
}

void dfs(int s = 1, int e = 0) {
    lev[s] = lev[e]+1;
    for (auto [u,w] : adj[s]) if (u != e) {
        dep[u] = dep[s]+w;
        spt[u][0] = s;
        dfs(u,s);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n-1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x+1].emplace_back(y+1,z);
        adj[y+1].emplace_back(x+1,z);
    }
    dfs();
    REP(i,1,lgN-1) REP(j,1,n) spt[j][i] = spt[spt[j][i-1]][i-1];
    REP(i,1,n) REP(j,1,n) {
        int x = lca(i,j);
        if (dep[i]+dep[j]-2*dep[x] == k) {
            answer = min(answer,lev[i]+lev[j]-2*lev[x]);
        }
    }
    if (answer == INF) cout << -1;
    else cout << answer;
}
