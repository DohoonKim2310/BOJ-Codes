#include <bits/stdc++.h>
#define cross(u, v) (conj(u)*(v)).imag() //v에 꼭 괄호를 씌워야 함.
using namespace std;
using V = complex<long double>;
const int N = 50;

int main() {
    int n, i, j, ans = 0; cin >> n;
    V b[n]; //building의 b를 따와 명명함.
    for (i = 0; i < n; ++i) {
        long double y; cin >> y;
        b[i] = {i, y}; //각각 x좌표, y좌표를 나타냄.
    }
    for (i = 0; i < n; ++i) {
        int cnt = 0;
        if (i+1 < n) {
            V p1 = b[i+1]; ++cnt; //인접한 건물은 무조건 볼 수 있음.
            for (j = i+1; j < n; ++j)
                if (cross(p1-b[i], b[j]-p1) > 0) {
                    p1 = b[j];
                    ++cnt;
                }
        }
        if (i > 0) {
            V p2 = b[i-1]; ++cnt;
            for (j = i-1; j >= 0; --j)
                if (cross(p2-b[i], b[j]-p2) < 0) {
                    p2 = b[j];
                    ++cnt;
                }
        }
        ans = max(ans, cnt); //cnt는 b[i]에서 볼 수 있는 총 건물의 수.
    }
    cout << ans;
}
