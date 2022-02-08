#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
#define hi first
#define sp second
ll input[100001];
vector<ll> ansArray;
 
int main() {
    while(1) {
        int n; cin >> n;
		ll ans = 0;
        if (!n) break;
        stack<pl> s;
        pl tmp;
        for (int i = 0; i < n; ++i) cin >> input[i];
        for (ll i = 0; i < n; ++i) {
            tmp = {input[i], i};
            while (!s.empty() && s.top().hi > input[i]) {
                ans = max(ans, s.top().hi*(i-s.top().sp));
                tmp.sp = min(s.top().sp, tmp.sp);
                s.pop();
            }
            s.push(tmp);
        }
        while (!s.empty()) {
            ans = max(ans, s.top().hi*(n-s.top().sp));
            s.pop();
        }
        ansArray.push_back(ans);
    }
    for (auto& p: ansArray) cout << p << '\n';
}
