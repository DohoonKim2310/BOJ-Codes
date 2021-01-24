#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define EB emplace_back
#define endl '\n'
#define REP1(i,b) for (int i = 1; i <= b; ++i)

const int N = 501;
vector<int> adj[N], sorted_list;
int dp[N], cost[N];
bool state[N];

void dfs(int s) {
    if (state[s]) return;
    for (int u : adj[s]) dfs(u);
    state[s] = true;
    sorted_list.EB(s);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP1(i,n) {
        cin >> cost[i];
        int s; cin >> s;
        while (s+1) {
            adj[s].EB(i);
            cin >> s;
        }
    }
    REP1(i,n) if (!state[i]) dfs(i);
    for (int i = n-1; i >= 0; --i) {
        int s = sorted_list[i];
        if (dp[s] == 0) dp[s] = cost[s];
        for (int u : adj[s]) {
            dp[u] = max(dp[u], dp[s]+cost[u]);
        }
    }
    REP1(i,n) cout << dp[i] << endl;
    return 0;
}
