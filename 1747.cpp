#include <iostream>
#include <cmath>
#define digit(n, k) int(n/pow(10, k-1))%10
using namespace std;
bool sieve[1003002];

bool isPalindrome(int p) {
    int x = 1, y = log(p)/log(10)+1;
    while (x <= y)
        if (digit(p, x++) != digit(p, y--)) return false;
    return true;
}

int main() {
    int n, x = 1; cin >> n;
    while (1) {
        if (sieve[++x]) continue;
        if (x >= n && isPalindrome(x)) break;
        for (int u = 2*x; u <= 1003001; u += x) sieve[u] = 1;
    }
    cout << x;
}
