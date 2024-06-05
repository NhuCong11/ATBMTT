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

bool isPrime(int n, int k) {
   if (n <= 1 || n == 4) return false;
   if (n <= 3) return true;

   while (k > 0) {
       int a = 2 + rand()%(n-4);
       if (calcExponent(a, n-1, n) != 1)
          return false;

       k--;
    }

    return true;
}

int main() {
    int k, n;
    
    cout << "Nhap vao so n: ";
    cin >> n;
    
    cout << "Nhap vao so k: ";
    cin >> k;
    
    isPrime(n, k)? cout << "->" << n << " la so nguyen to.": cout << "->" << n << " khong la so nguyen to.";
    return 0;
}