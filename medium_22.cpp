#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    double result = 0.0;
    double resultOneByOne = 0.0;
    int point = 0;
    for (int i = 1; i <= n; i++) {
        point = i;
        resultOneByOne = (double)1 / n;
        while (point < k) {
            point *= 2;
            resultOneByOne *= (double)1 / 2;
        }
        result += resultOneByOne;
    }
    printf("%.12f\n", result);
}