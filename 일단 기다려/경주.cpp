#include <bits/stdc++.h>
using namespace std; using ii = pair<int,int>; using ll = long long;
void o_o(){ cerr << endl; }
template <class H, class...T> void o_o(H h,T...t) { cerr << ' ' << h; o_o(t...); }
#define debug(...) cerr<<'['<<#__VA_ARGS__<<"]:",o_o(__VA_ARGS__)
#define rep(i,a,b) for (auto i = (a); i <= (b); ++i)
#define all(x) (x).begin(), (x).end()
#define size(x) int((x).size())
#define Mup(x,y) x = max(x,y)
#define mup(x,y) x = min(x,y)

const int N = 2e5+3, K = 1e6+3;
int n, k;
vector<ii> adj[N];

namespace subtask1 {
    int answer = 1e9;
    void dfs(ll dist, int count, int s, int e) {
        if (dist == k) mup(answer,count);
        for (auto [u,w] : adj[s]) if (u != e) {
            dfs(dist+w,count+1,u,s);
        }
    }
    void solve() {
        rep(i,1,n) dfs(0,0,i,0);
        if (answer < n) printf("%d", answer);
        else puts("-1");
    }
}
namespace subtask2 {
    void solve() {
        subtask1::solve();
    }
}
namespace subtask3 {
    const int K = 103;
    ii dp1[N][K], dp2[N][K];
    int answer = 1e9;
    void dfs(int s = 1, int e = 0) {
        vector<ii> v[K];
        for (auto [u,w] : adj[s]) if (u != e) {
            dfs(u,s);
            rep(i,0,k) v[i].push({dp[u][i],u});
        }
        rep(i,0,k) sort(all(v[i]));
        
    }
    void solve() {
        fill(dp[0],dp[N],1e9);
        dfs();
        if (answer < n) printf("%d", answer);
        else puts("-1");
    }
}
namespace subtask4 {
    void solve() {
        
    }
}
int main() {
    scanf("%d %d", &n, &k);
    rep(i,1,n-1) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        ++a, ++b;
        adj[a].emplace_back(b,w);
        adj[b].emplace_back(a,w);
    }
    if (n <= 100 and k <= 100) subtask1::solve();
    else if (n <= 1000 and k <= 1'000'000) subtask2::solve();
    else if (n <= 200'000 and k <= 100) {
        subtask3::solve();
    } else {
        subtask4::solve();
    }
}