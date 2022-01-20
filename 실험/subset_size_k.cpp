#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define el '\n'
using namespace std; using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int64_t n = 36, m = 18;
    double kitamasa_time = 0, pllk_time = 0;
    time_t s;
    int cnt = 1;
    int64_t count;
    REP(i,1,cnt)
    {
        s = time(NULL), count = 0;
        for (int64_t x, y, b = (1LL<<m)-1; b < 1LL<<n;
            x = b&-b, y = b+x, b = ((b&~y)/x>>1)|y) {
            // Code...
            count++;
        }
        kitamasa_time += time(NULL)-s;
        cout << count << el;
        s = time(NULL), count = 0;
        for (int64_t b = 0; b < 1LL<<n; ++b) {
            if (__builtin_popcountll(b) == m) {
                // Code...
                count++;
            }
        }
        pllk_time += time(NULL)-s;
        cout << count << el;
    }
    cout << "kitamasa: " << kitamasa_time/cnt << "s\n";
    cout << "pllk: "<< pllk_time/cnt << "s\n";
}
/*
(n,m)=(26,13)
  kitamasa: 0.2s
  pllk: 0.3s
(n,m)=(28,14)
  kitamasa: 0.6s
  pllk: 1s
(n,m)=(30,15)
  kitamasa: 2.4s
  pllk: 4.1s
(n,m)=(32,16)
  kitamasa: 9s
  pllk: 13s
*/
