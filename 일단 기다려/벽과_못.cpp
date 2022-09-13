#include <bits/stdc++.h>
using namespace std; using ii = pair<int,int>;
using ll = long long; using ld = long double;
#define _(x) const x&
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define ZIP(x) (x).erase(unique((x).begin(),(x).end()),(x).end())
#define MP make_pair
#define mup(x,y) x = min(x,y)
#define Mup(x,y) x = max(x,y)
#define size(x) int((x).size())
#pragma region Geometry
using P = complex<ll>; using Poly = vector<P>;
constexpr ld PI = acos(-1.0L), TAU = 2*PI;
#define X real()
#define Y imag()
#define dot(u,v) (conj(u)*(v)).X
#define cross(u,v) (conj(u)*(v)).Y
#define norm(u) dot(u,u)
int ccw(P a, P b, P c) {
    auto v = cross(b-a,c-b);
    if (v < 0) return -1;
    else if (v > 0) return 1;
    return 0;
}
ld abs(P u) {return sqrt(ld(norm(u)));}
istream &operator >> (istream &is, P &p) {ll x, y; is >> x >> y; p = {x,y}; return is;}
namespace std { bool operator < (P u, P v) {return u.X == v.X ? u.Y < v.Y : u.X < v.X;} }
#pragma endregion

Poly convex_hull(vector<P> &p) {
    sort(p.begin(),p.end());
    Poly up(size(p)), lo(size(p));
    int u = 0, l = 0, i = 0, j = size(p)-1;
    REP(_,1,size(p)) {
        while (u >= 2 and ccw(up[u-2],up[u-1],p[i]) >= 0) --u;
        while (l >= 2 and ccw(lo[l-2],lo[l-1],p[j]) >= 0) --l;
        up[u++] = p[i++], lo[l++] = p[j--];
    }
    up.resize(u-1), lo.resize(l-1);
    up.insert(up.end(),lo.begin(),lo.end());
    return up;
}

const int N = 3e5+3;
int n;
vector<int> p;
string s;
stack<ci> st;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (auto &e : p) cin >> e;
    cin >> s;
    p = convex_hull(p);
    for (char c : s) {
        
    }
}
/*
* 처음에는 스택이랑 bool 배열 써가지고 점 역순 추가를 구성한다.
    - 대충 set을 x 기준 / y 기준으로 하나씩 만들어주면 될 것 같음.
    - 아니다 어차피 정렬시키고 나서 빼는건데 뭘
    - deque 정도 쓰면 되겠는데? 아님 two pointer 쓰거나 알아서
* 대충 2각형이나 3각형 정도부터 시작해서 넓이를 넓혀가는 과정을 역순으로 출력하면 될 거임.
    - 사분면마다 해당 deque를 만들어줘서, 예를들어 R에 점이 추가되는 과정이라면
        * 1사분면에서 반시계방향으로 CCW 만족할떄까지 빼주고
        * 4사분면에서 시계방향으로 CCW 만족할떄까지 빼주고
        * 마지막에 대충 추가되는 점 넣어서 마무리. 양쪽에 다 넣는 편이 깔끔할듯?
        * 각 점 입장에서 1번씩 delete 되는거니까 O(n)임.
*/