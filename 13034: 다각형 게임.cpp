#include <bits/stdc++.h>
using namespace std;
int g[1001] = {0,};
int mex(int n) {
    int mex = 0; set<int> s;
    for (int i = 0; i <= n/2; ++i) s.insert(g[i]^g[n-i]);
    for (auto a: s) {
        if (a == mex) ++mex;
        else break;
    }
    return mex;
}
int main() {
    int N; cin >> N;
    for (int i = 2; i <= N; ++i) g[i] = mex(i-2);
    if (g[N]) cout << 1;
	else cout << 2;
}
