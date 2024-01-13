#include "bits/stdc++.h"
using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long betweenNum = 0;
    if ((a > b) || (n == 1 && a != b)) {
        cout << 0 << endl;
        return 0;
    } else if ((n == 1 && a == b) || n == 2) {
        cout << 1 << endl;
        return 0;
    } else {
        betweenNum = n - 2;
        long long maxAndMinDiff = b - a;
        long long result = 0;
        result = maxAndMinDiff * betweenNum;
        result += 1;
        cout << result << endl;
        return 0;
    }
}