#include <bits/stdc++.h>
using namespace std;
const int maxn = 9973;
 
int dist[maxn+1], S, E;
bool sieve[maxn+1], visited[maxn+1];
queue<int> q;
vector<int> adj[maxn+1];
 
bool isPrimeRoute(int a, int b) {
    #define digit(x) (x%m)-(x%(m/10))
    if (sieve[a] || sieve[b]) return false;
    int cnt = 0;
    for (int m = 10; m <= 10000; m *= 10) {
        if (digit(a) != digit(b)) ++cnt;
    }
    return cnt == 1;
}
 
void bfs() {
    q.push(S); dist[S] = 0; visited[S] = true;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u: adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[s]+1;
            q.push(u);
        }
    }
}
 
void pretreatment() {
    //Eratos algorithm
    for (int x = 2; x <= maxn; ++x) {
        if (sieve[x]) continue;
        for (int u = 2*x; u <= maxn; u += x) {
            sieve[u] = 1;
        }
    }
    //Make graph
    for (int i = 1000; i < maxn; ++i) {
        for (int j = i+1; j <= maxn; ++j) {
            if (isPrimeRoute(i, j)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}
 
int main() {
    pretreatment();
    int t; cin >> t;
    while (t--) {
        cin >> S >> E;
        bfs();
        cout << dist[E] << '\n';
        memset(dist, 0, maxn+1);
        memset(visited, 0, maxn+1);
    }
    return 0;
}
