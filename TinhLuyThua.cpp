#include <bits/stdc++.h>
using namespace std;

long long calcExponent(long long a, long long b, long long n) {
    long long f = 1;
    for (int i = log2(b); i >= 0; i--) {
        f = (f * f) % n;
        // so sanh bit thu i cua b voi 1, toan tu & la so sanh tung bit voi nhau
        if ((b >> i) & 1) {
            f = (f * a) % n;
        }
    }
    return f;
}

int main() {
    long long a, b, n;
    
    cout << "Nhap vao so a: ";
    cin >> a;
    cout << "Nhap vao so b: ";
    cin >> b;
    cout << "Nhap vao so n: ";
    cin >> n;
    
    cout << "-> " << a << "^" << b << " mod " << n << ": " << calcExponent(a, b, n);
    return 0;
}