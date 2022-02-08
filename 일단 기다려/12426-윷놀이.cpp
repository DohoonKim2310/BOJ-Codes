#include <bits/stdc++.h>
#define size(x) int((x).size())
using namespace std;
void solution(int);
void make_link();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    make_link();
    int t; cin >> t;
    while (t-- > 0) {
        solution(t);
    }
}

vector<int> link[29];
void make_link() {
    for (int i = 0; i < 20; ++i) {
        link[i].push_back((i+1)%20);
    }
    link[5].push_back(20);
        link[20].push_back(21);
        link[21].push_back(22);
    link[10].push_back(25);
        link[25].push_back(26);
        link[26].push_back(22);
    link[15].push_back(24);
        link[24].push_back(23);
        link[23].push_back(22);
    link[22].push_back(27);
        link[27].push_back(28);
        link[28].push_back(0);
}

void go(int cur, int step) {
    
}

auto input() {
    int n, a, b; cin >> n >> a >> b;
    vector<int> m(n), A(a), B(b);
    for (auto &mv : m) {
        string s; cin >> s;
        if (s == "Do") mv = 1;
        if (s == "Gae") mv = 2;
        if (s == "Gul") mv = 3;
        if (s == "Yut") mv = 4;
        if (s == "Mo") mv = 5;
    }
    for (auto &_a : A) cin >> _a;
    for (auto &_b : B) cin >> _b;
    return make_tuple(m,A,B);
}
void solution(int tc) {
    int u; cin >> u;
    auto [moves,a,b] = input();
    for (auto m : moves) {
        go()
    }
}
