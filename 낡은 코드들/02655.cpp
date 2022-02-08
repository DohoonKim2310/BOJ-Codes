#include <iostream>
#include <tuple>
#include <algorithm>
#include <stack>
#define W get<0>
#define A get<1>
#define H get<2>
#define I get<3>
using namespace std;
using ti = tuple<int,int,int,int>;
const int N = 201;
ti blocks[N];
int dp[N], from[N];

void print(int x) {
    stack<int> ans;
    while (x) {
        ans.push(I(blocks[x]));
        x = from[x];
    }
    cout << ans.size() << '\n';
    while (!empty(ans)) {
        cout << ans.top() << '\n';
        ans.pop();
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        int a, h, w;
        cin >> a >> h >> w;
        blocks[i] = {w, a, h, i};
    }
    sort(blocks+1, blocks+n+1);
    
    for (int i = 1; i <= n; ++i) {
        dp[i] = H(blocks[i]);
        for (int j = 1; j < i; ++j)
            if (A(blocks[j]) < A(blocks[i]))
                if (dp[i] < dp[j]+H(blocks[i])) {
                    dp[i] = dp[j]+H(blocks[i]);
                    from[i] = j;
                }
    }
    print(max_element(dp+1, dp+n+1)-dp);
    return 0;
}
