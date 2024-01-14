#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    map<string, int> num;
    int result = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        num[to_string(a[i])]++;
    }
    vector<int> v;
    for (auto &[key, value] : num) {
        v.push_back(value);
    }
    sort(v.begin(), v.end());
    int kindDiff = num.size() - k;
    if (kindDiff <= 0) {
        cout << 0 << endl;
        return 0;
    } else {
        for (int i = 0; i < kindDiff; i++) {
            result += v[i];
        }
        cout << result << endl;
        return 0;
    }
}