#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    long k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long t0 = 0;
    long t1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                t0++;
            }
        }
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                t1++;
            }
        }
    }
    long p0 = (t0 * k) % (1000000000+7);
    long p1 = (((k * (k - 1)) / 2) % (1000000000+7)*(t0+t1)) % (1000000000+7);
    cout << (p0+p1) % (1000000000+7) << endl;
}