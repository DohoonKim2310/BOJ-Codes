#include <iostream>
using namespace std;

int main() {
    int n, ans = 0, s, tmp = 1; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        ans ^= s;
        tmp &= s;
    }
    if (tmp && n%2) cout << "cubelover";
    else if (tmp && !(n%2)) cout << "koosaga";
    else if(ans != 0) cout << "koosaga";
    else cout << "cubelover";
}
