#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define SIZE(x) int(x.size())
#define MP make_pair

const int N = 1e4+3, M = 2e4+3;
int n, m, x;
int t[N];
vector<ii> adj[N];

void input() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> x;
    // n rooms, m 복도, 온도 적응까지 x
    // n번 노드에 출구가 있다
    // 저택 탈출까지 걸리는 최소 시간?
    REP(i,1,n) {
        cin >> t[i];
        // t=0:cold
        // t=1:normal
        // t=2:hot
        // t[1] = 0 -> cold, start at 1.
    }
    REP(i,1,m) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].emplace_back(b,d);
        adj[b].emplace_back(a,d);
    }
}
int main() {
    input();
}
