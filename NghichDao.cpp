#include <bits/stdc++.h>
using namespace std;

int NghichDao(int a, int n) {
    int r0, r1, r2, q, t0, t1;
    
    r0 = n;
	r1 = a;
    t0 = 0;
    t1 = 1;
    r2 = r0 % r1;
    
    while (r1 != 1) {
        q = r0 / r1;
        r2 = r0 % r1;
        
        int temp = t1;
        t1 = (t0 - q * t1) % n;
        
        if (r2 == 0) {
        	return -1;
        }
            
        if (t1 < 0) {
        	t1 += n;
        }
            
        t0 = temp;
        r0 = r1;
        r1 = r2;
    }
    return t1;
}

int main() {
	int a, n;
	cout << "Nhap so a: ";
	cin >> a;
	cout << "Nhap so n: ";
	cin >> n;
	if (NghichDao(a, n) < 0) {
		cout << "Khong ton tai nghich dao";
	} else {
		cout << "\nNghich dao cua " << a << "^-1" << " mod " << n << " la " << NghichDao(a, n);
	}
}

