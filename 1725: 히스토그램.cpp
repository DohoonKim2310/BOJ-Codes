#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
#define hi first
#define sp second
ll data_[100001], ans;
 
int main() {
    int n; cin >> n;
    stack<pl> s;
    pl tmp;
    for (int i = 0; i < n; ++i) cin >> data_[i];
    for (ll i = 0; i < n; ++i) {
        tmp = {data_[i], i};
        while (!s.empty() && s.top().hi > data_[i]) {
            ans = max(ans, s.top().hi*(i-s.top().sp));
            tmp.sp = min(s.top().sp, tmp.sp);
            s.pop();
        }
        s.push(tmp);
    }
    while (!empty(s)) {
        ans = max(ans, s.top().hi*(n-s.top().sp));
        s.pop();
    }
    cout << ans;
}
