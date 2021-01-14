#include <iostream>
using namespace std;

int main() {
	int M, nimSum = 0; cin >> M;
	for (int i = 0; i < M; ++i) {
		int g; cin >> g; 
		nimSum ^= g;
	}
	if (nimSum) cout << "koosaga";
	else cout << "cubelover";
}
