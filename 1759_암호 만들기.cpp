#include <bits/stdc++.h>
#define isVowel in[k] == 'a' || in[k] == 'e' || in[k] == 'i' || in[k] == 'o' || in[k] == 'u'
using namespace std;
int l, c, consonant;
char in[20];
bool isVowelChosen;
vector<char> pswd;

void search(int k) {
    if (pswd.size() == l) {
		if (!isVowelChosen || consonant < 2) return;
        for (auto p: pswd) cout << p;
        cout << '\n';
        return;
    }
	else if (k >= c) return;
	int tmp1 = consonant; bool tmp2 = isVowelChosen;
	if (isVowel) isVowelChosen = true;
	else ++consonant;
	pswd.push_back(in[k]);
    search(k+1);
	consonant = tmp1, isVowelChosen = tmp2;
    pswd.pop_back();
	search(k+1);
}

int main() {
    cin >> l >> c;
    for(int i = 0; i < c; ++i) cin >> in[i];
	sort(in, in+c);
    search(0);
}
