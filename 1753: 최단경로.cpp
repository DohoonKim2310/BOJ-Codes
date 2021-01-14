#include <iostream>
#include <vector>
#include <queue>
#define REPh(i, a, b) for (int i = a; i < b; ++i)
#define REPc(i, a, b) for (int i = a; i <= b; ++i)
#define PB push_back
using namespace std;
typedef pair<int, int> pii;
const int INF = 300003;

vector<pii> adj[20003];
int V, E, K;

void input() {
    cin >> V >> E >> K;
    REPc (i, 1, E) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].PB({v, w});
    }
}

int main() {
    input();
    int dist[V+1];
    bool visited[20001] = {0,};
    priority_queue<pii> q;
    REPc (i, 1, V) dist[i] = INF;
    dist[K] = 0; q.push({0, K});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto u: adj[a]) {
            int b = u.first, w = u.second;
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b], b});
            }
        }
    }
    REPc (i, 1, V) {
        if (dist[i] < INF) cout << dist[i] << '\n';
        else cout << "INF\n";
    }
}
