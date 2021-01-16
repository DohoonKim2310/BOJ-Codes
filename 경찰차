#include "CPheader.hpp"
#define F first
#define S second
using namespace std;
using ll =  long long;
using pi = pair<int,int>;
const int N = 1001;
int n, w, ans[N], dp[N][N];
pi p[N], from[N][N];

void tracking(int idx, pi t) {
   if (t == make_pair(0,0)) return;
   pi before = from[t.F][t.S];
   if (t.F == idx) while (idx > t.S) ans[idx--] = 1;
   else while (idx > t.F) ans[idx--] = 2;
   tracking(idx, before);
   return;
}

inline int d(int a, int b) {
   return abs(p[a].F-p[b].F)+abs(p[a].S-p[b].S);
}

void print() {
   int mn = 0x7f7f7f7f;
   pi fin;
   for (int i = 0; i < w; i++) {
       if (mn > dp[w][i]) {
           mn = dp[w][i];
           fin = {w,i};
       }
       if (mn > dp[i][w]) {
           mn = dp[i][w];
           fin = {i,w};
       }
   }
   tracking(w, fin);
   cout << mn << '\n';
   for (int i = 1; i <= w; i++) cout << ans[i] << '\n';
}

int main() {
   cin >> n >> w;
   REP1(i,w) cin >> p[i].F >> p[i].S;
   dp[0][1] = abs(n-p[1].F)+abs(n-p[1].S);
   dp[1][0] = abs(1-p[1].F)+abs(1-p[1].S);
   REPc(i,2,w) {
       dp[i][i-1] = dp[0][i-1]+ abs(1-p[i].F)+abs(1-p[i].S);
       from[i][i-1] = {0,i-1};
       REPh(j,1,i-1) {
           if (dp[i][i-1] > dp[j][i-1]+d(j,i)) {
               dp[i][i-1] = dp[j][i-1]+d(j,i);
               from[i][i-1] = {j,i-1};
           }
       }
       dp[i-1][i] = dp[i-1][0]+abs(n-p[i].F)+abs(n-p[i].S);
       from[i-1][i] = {i-1,0};
       REPh(j,1,i-1) {
           if (dp[i-1][i] > dp[i-1][j]+d(j,i)) {
               dp[i-1][i] = dp[i-1][j]+d(j,i);
               from[i-1][i] = {i-1,j};
           }
       }
       REP0(j,i-1) {
           dp[j][i] = dp[j][i-1]+d(i-1,i);
           dp[i][j] = dp[i-1][j]+d(i-1,i);
           from[j][i] = {j,i-1};
           from[i][j] = {i-1,j};
       }
   }
   print();
   return 0;
}
