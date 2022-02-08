#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define size(x) int((x).size())
#define el '\n'
using namespace std; using ll = long long;

char prime_count[1'000'001];
char pc[101][1'000'001];

void push_factors(char p[], int n) {
    for (int x = 2; x*x <= n; ++x) {
        while (n%x == 0) p[x]++, prime_count[x]++, n /= x;
    }
    if (n > 1) p[n]++, prime_count[n]++;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, tmp = 0; cin >> n;
    vector<int> a(n);
    for (auto &s : a) {
        cin >> s;
        push_factors(pc[tmp++],s);
    }
    int ans1 = 1, ans2 = 0;
    for (int p = 2; p <= 1'000'000; ++p) {
        if (prime_count[p] > 0) {
            ans1 *= pow(p,prime_count[p]/n);
            prime_count[p] /= n;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int p = 2; p <= 1'000'000; ++p) {
            if (prime_count[p] > 0)
                ans2 += max(0,prime_count[p]-pc[i][p]);
        }
    }
    cout << ans1 << ' ' << ans2;
}
