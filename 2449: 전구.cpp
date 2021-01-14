#include <iostream>
#include <vector>
#define F first
#define S second
#define REP1(i,n) for(int i=1;i<=n;++i)
#define REPh(i,a,b) for(int i=a;i<b;++i)
using namespace std;
pair<int,int> value[201][201]; //{색깔,최솟값}
bool memo[201][201] {0,};
vector<int> blubs;

pair<int, int> func(int f, int b) {
    if (memo[f][b]) return value[f][b];
    memo[f][b] = true;
    if (f == b) return value[f][b] = {blubs[f-1], 0};
    value[f][b].S = 9000000;
    REPh(i, f, b) {
        pair<int,int> x = func(f, i), y = func(i+1, b);
        if (value[f][b].S > x.S+y.S && x.F == y.F)
            value[f][b] = {x.F, x.S+y.S};
        else if (value[f][b].S > x.S+y.S+1 && x.F != y.F)
            value[f][b] = {x.F, x.S+y.S+1};
    }
    return value[f][b];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K, ans = 1000; cin >> N >> K;
    blubs.resize(N);
    for (auto& s : blubs) cin >> s; //blubs는 0번방부터 시작
    blubs.erase(unique(begin(blubs), end(blubs)), end(blubs));
    N = (int)size(blubs);
    REP1(i, N) func(1, i);
    REP1(i, K) ans = min(ans, value[1][N].S);
    cout << ans;
}
