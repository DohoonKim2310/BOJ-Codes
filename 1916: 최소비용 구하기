#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define REP1(i,n) for(int i=1;i<=n;++i)
#define PB push_back
#define nxt first
#define wei second
#define dis first
#define nod second

const int maxn = 1000, INF = (int)2e31-1;
int n, m, dist[maxn+1], s, e;
bool visited[maxn+1];
vector<pii> adj[maxn+1];

void input() {
    cin >> n >> m;
    REP1(i, m) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].PB({b,w});
    }
    cin >> s >> e;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    input();
    //dijkstra
    priority_queue<pii> q;
    REP1(i,n) dist[i] = INF;
    dist[s] = 0; q.push({0,s});
    while (!q.empty()) {
        int a = q.top().nod; q.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto u: adj[a]) {
            int b = u.nxt, w = u.wei;
            if (dist[b] > dist[a]+w) {
                dist[b] = dist[a]+w;
                q.push({-dist[b], b});
            }
        }
    }
    cout << dist[e] << '\n';
}
