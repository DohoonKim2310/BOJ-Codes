#pragma region Code by hgmhc
// g++-11 -std=c++17 -O2 -Wall -Wno-unknown-pragmas -DLOCAL
#include <bits/stdc++.h>
using namespace std; using ll = long long; using ii = pair<int,int>; using iii = tuple<int,int,int>;
template <typename T> using Operation = function<T(const T&,const T&)>;
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define PER(i,a,b) for (auto i = (b); i >= (a); --i)
#define size(x) int((x).size())
constexpr int floor_log2(int x) {assert(x > 0); return 31-__builtin_clz(x);}
constexpr int ceil_log2(int x) {assert(x > 0); return 31-__builtin_clz(x)+bool(x&(x-1));}
constexpr ll floor(ll p, ll q) { return p/q-((p^q) < 0 and p%q); }
constexpr ll ceil(ll p, ll q) { return p/q+((p^q) > 0 and p%q); }
#define PB push_back
#define MP make_pair
#define ALL(a,n) (a)+1,(a)+(n)+1
#define SORT(a,b,c) sort(ALL(a,b),FC(c))
#define ZIP(x) sort((x).begin(),(x).end()), (x).erase(unique((x).begin(),(x).end()),(x).end())
#define mup(x,y) x = min(x,y)
#define Mup(x,y) x = max(x,y)
#define F first
#define S second
#define el '\n'
void solution(); int main() {cin.tie(0)->sync_with_stdio(0); solution();}
#pragma endregion

#define FC(a) [](const auto &x, const auto &y){return a;}

const int V = 1e5+3, E = 3e5+3, INF = E<<1;
int v, e;
vector<int> adj[V];
pair<int,int> dist[V];
bool ready[V];
int indegree[V];

void dfs(int s) {
    if (ready[s]) return;
    ready[s] = true;
    vector<int> v;
    for (auto u : adj[s]) {
        dfs(u);
        mup(dist[s].F,dist[u].S);
        v.push_back(dist[u].F);
    }
    sort(v.rbegin(),v.rend()), iota(v.begin(),v.end(),0);
    mup(dist[s].S,*min_element(v.begin(),v.end()));
}

void input() {
    cin >> v >> e;
    fill(ALL(dist,v),MP(INF,INF));
    REP(i,1,e) {
        int a, b; cin >> a >> b;
        adj[a].PB(b);
        indegree[b]++;
    }
}
void solution() {
    input();
    dist[v].S = 0;
    int answer = INF;
    REP(i,1,v) {
        dfs(i);
        if (indegree[i] == 1) {
            mup(answer,dist[i].S);
        }
    }
    cout << answer;
}
/*
만약 준표가 먼저 대화를 시작했다면 이를 포함한 홀수번째 화제를 고르고, 만영이는 짝수번째 화제를 고르는 식이다
*/
