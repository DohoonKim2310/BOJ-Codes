#include <iostream>
using namespace std;

int main() {
    int n, ans = 0, s; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        ans ^= s;
    }
    if(ans) cout << "koosaga";
    else cout << "cubelover";
}
