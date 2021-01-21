#include <iostream>
#include <utility>
#include <algorithm>
#define F first
#define S second
using namespace std;
using pi = pair<int,int>;
const int maxn = 200;
pi sz[maxn+1];
int dp[maxn+1];

bool cmp(const pi& a, const pi& b) {return a.F*a.S > b.F*b.S;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {cin >> sz[i].F >> sz[i].S; if (sz[i].F > sz[i].S) swap(sz[i].F, sz[i].S);}
    sort(sz, sz+n+1, cmp);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            if (sz[j].F >= sz[i].F && sz[j].S >= sz[i].S) dp[i] = max(dp[i], dp[j]+1);
    cout << *max_element(dp, dp+n+1);
}
