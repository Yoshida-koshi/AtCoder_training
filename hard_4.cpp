#include "bits/stdc++.h"
using namespace std;

int main() {
    long long a, b, x;
    cin >> a >> b >> x;
    long long result = 0;
    if (a == 0 && b < x) {
        cout << 1 << endl;
        return 0;
    } else if (a == 0 && x > 1) {
        result++;
    }
    long long resultB = b / x;
    long long resultA = (a - 1) / x;
    result += resultB - resultA;
    cout << result << endl;
}