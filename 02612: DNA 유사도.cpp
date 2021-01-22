#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#define F first
#define S second
using namespace std;
using pi = pair<int,int>;

const int N = 1003;
int dp[N][N], n, m;
string a, b;
vector<char> ans1, ans2;

void track(pi x) {
    if (x.F <= 0 || x.S <= 0) return;
//    cout << x.F-1 << ' ' << x.S-1 << endl;
    if (!dp[x.F][x.S]) return;
    ans1.emplace_back(a[x.F-1]);
    ans2.emplace_back(b[x.S-1]);
    if (dp[x.F][x.S] == dp[x.F-1][x.S]-2) {ans2.pop_back(); track({x.F-1, x.S});}
    else if (dp[x.F][x.S] == dp[x.F][x.S-1]-2) {ans1.pop_back(); track({x.F, x.S-1});}
    else track({x.F-1, x.S-1});
    return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a >> m >> b;
	//치환, 삭제, 추가의 경우는 2를 빼준다
	//그대로 같다면 3을 더한다
	//역추적 과정이 필요하다
	//dp[i,j]: a[0...i-1]와 b[0...j-1]의 유사도
    int mx = -1;
    pi maxpos;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+3;
            dp[i][j] = max(dp[i][j], max(dp[i-1][j-1], max(dp[i][j-1], dp[i-1][j]))-2);
            if (mx < dp[i][j]) {mx = dp[i][j]; maxpos = {i, j};}
		}
	}
    //print
	cout << mx << '\n';
	track(maxpos);
    reverse(ans1.begin(), ans1.end()); for (auto p : ans1) cout << p; cout << '\n';
    reverse(ans2.begin(), ans2.end()); for (auto p : ans2) cout << p; cout << '\n';
//    for (int i = 0; i <= n; ++i) for (int j = 0; j <= m; ++j) cout << dp[i][j] << " \n"[j == m];
	return 0;
}
