#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+1;
int prefix[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int s; cin >> s;
        prefix[i] = prefix[i-1]+s;
    }
    int mx = 0, mn = 0;
    for (int i = m; i <= n; ++i) {
        mn = min(mn, prefix[i-m]);
        mx = max(mx, prefix[i]-mn);
    }
    cout << mx;
    return 0;
}
