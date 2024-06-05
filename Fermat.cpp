#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}


int ModPower(int a, int b, int n) {
    if (b == 1) {
        return a;
    } else {
        int x = ModPower(a, b / 2, n);
        if (b % 2 == 0) {
            return (x * x) % n;
        } else {
            return (x * x * a) % n;
        }
    }
}


bool FermatTesting(int n, int k) {
    for (int i = 0; i < k; ++i) {
        int a = rand() % (n - 1) + 2; 
        
        if (GCD(a, n) != 1) {
            return false;
        }
        
        if (ModPower(a, n - 1, n) != 1) {
            return false; 
        }
    }
    return true; 
}

main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int k = 10;
    cout << "Nhap k: ";
    cin >> k;
    if (FermatTesting(n, k)) {
        cout << n << " la so nguyen to." << endl;
    } else {
        cout << n << " khong la so nguyen to." << endl;
    }

}
