#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    long long n;
    long long phi = 1;
    cin >> n;
    for (long long p = 2; p*p <= n; p++) {
        int e = 0;
        while (n%p == 0) {
            n /= p;
            e++;
        }
        if (e) {
            phi *= pow(p, e-1)*(p-1);
        }
    }
    if (n > 1) phi *= n-1;
    cout << phi;
    return 0;
}

