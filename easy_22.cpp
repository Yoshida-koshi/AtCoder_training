#include "bits/stdc++.h"
using namespace std;

int a[100];

int main() {
    int n, x;
    cin >> n >> x;
    int result = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        if (i == 0 && x - a[i] < 0) {
            result = 0;
            break;
        } else if (x - a[i] < 0) {
            break;
        } else if (i == n - 1 && x - a[i] > 0) {
            break;
        } else {
            x -= a[i];
            result++;
        }
    }

    cout << result << endl;
} 