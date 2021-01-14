#include <iostream>
using namespace std;

int main() {
	int N, s, tmp = 0; cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		if (s%4 == 3) tmp ^= (s+1);
		else if (s%4 == 0) tmp ^= (s-1);
		else tmp ^= s;
	}
    if (tmp) cout << "koosaga";
	else cout << "cubelover";
}
