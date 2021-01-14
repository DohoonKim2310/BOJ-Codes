#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define hi first
#define index second
int ans[500001];
 
int main() {
    int N; cin >> N;
    stack<pi> s;
    for (int i = 1; i <= N; ++i) {
        int tmph; cin >> tmph;
        pi tmp = {tmph,i};
        while (!s.empty() && s.top().hi < tmp.hi) {
            s.pop();
        }
        if (!s.empty()) ans[i] = s.top().index;
        else ans[i] = 0;
        s.push(tmp);
    }
    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << ' ';
    }
}
