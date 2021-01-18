#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N = 1001;
vector<int> adj[N];
stack<int> sorted_list;
short state[N];

void dfs(int s) {
    if (state[s] == 2) return;
    if (state[s] == 1) {cout << 0; exit(0);}
	state[s] = 1;
	for (int u : adj[s]) dfs(u);
	state[s] = 2;
	sorted_list.emplace(s);
	return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
	while (m--) {
		int sz, s, e; cin >> sz >> s;
		while (--sz) {
			cin >> e;
			adj[s].emplace_back(e);
            s = e;
		}
	}
	while (n--) if (!state[n+1]) dfs(n+1);
    while (!empty(sorted_list)) {
        cout << sorted_list.top() << '\n';
        sorted_list.pop();
    }
	return 0;
}
