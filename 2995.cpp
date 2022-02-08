#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define mup(x,y) x = min(x,y)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long; using ii = pair<int,int>;
void solution(); int main() {ios::sync_with_stdio(0); cin.tie(0); solution();}
const int N = 100003;
int n, dp[N], cnt[N]; ii range[N];
#define L first
#define R second

void solution() {
    cin >> n; REP(i,1,n) cin >> range[i].L >> range[i].R;
    sort(range+1,range+n+1,[&](const ii a, const ii b) {
        if (a.R == b.R) return a.L > b.L;
        return a.R < b.R;
    });
    dp[0] = -10000003;
    REP(i,1,n) {
        cnt[i] = upper_bound(dp,dp+i,-range[i].L)-dp;
        mup(dp[cnt[i]],-range[i].L);
    }
    int pos = max_element(cnt+1,cnt+n+1)-cnt, nsz = cnt[pos];
    cout << cnt[pos] << el;
}
//dp[cnt[i]] > -range[i].L일 경우에도 link를 갱신하는 바람에 틀렸음.
//또 애초에 link는 최신의 것을 저장할 경우 인덱스 순서에 역전이 생길 수 있기 때문에 저런 식으로 역추적하는 것은 잘못됨.
