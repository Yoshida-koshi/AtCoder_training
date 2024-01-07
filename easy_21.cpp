#include"bits/stdc++.h"
using namespace std;

bool isPrimeNum(int x) {
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int x;
    cin >> x;
    while (true) {
        if (isPrimeNum(x)) {
            cout << x << endl;
            return 0;
        } else {
            x++;
        }
    } 
}