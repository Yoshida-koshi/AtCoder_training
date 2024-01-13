#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, d, x;
    cin >> n;
    cin >> d >> x;
    int a[n];
    int result = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int eatChocoDay = 1;
        int chocoNum = 0;
        while (eatChocoDay <= d) {
            chocoNum++;
            eatChocoDay += a[i];
        }
        result += chocoNum;
    }
    result += x;
    cout << result << endl;
}