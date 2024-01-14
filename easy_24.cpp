#include "bits/stdc++.h"
using namespace std;

int main() {
    int A, B, M;
    cin >> A >> B >> M;
    int a[A], b[B], c[M], x[M], y[M];
    int result = 0;
    int minPriceAfterDiscount = INT_MAX;
    for (int i = 0; i < A; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < B; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> x[i] >> y[i] >> c[i];
    }
    for (int i = 0; i < M; i++) {
        int priceAfterDiscount = a[x[i] - 1] + b[y[i] - 1] - c[i];
        if (priceAfterDiscount < minPriceAfterDiscount) {
            minPriceAfterDiscount = priceAfterDiscount;
        }
    }
    sort(a, a+A);
    sort(b, b+B);
    result = a[0] + b[0];
    if (result <= minPriceAfterDiscount) {
        cout << result << endl;
    } else {
        cout << minPriceAfterDiscount << endl;
    }
}