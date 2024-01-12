#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int s[m], c[m];
    vector<int> result(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> c[i];
    }
    if (m == 0 && n == 1) {
        cout << 0 << endl;
        return 0;
    } else if (m == 0) {
        cout << pow(10.0, (double) n - 1) << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        if ((n != 1 && s[i] == 1 && c[i] == 0) || (result[s[i] - 1] != -1 && result[s[i] - 1] != c[i])) {
            cout << -1 << endl;
            return 0;
        } else {
            result[s[i] - 1] = c[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == 0 && result[i] == -1) {
            result[i] = 1;
        } else if (result[i] == -1) {
            result[i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
    }
    printf("\n");
}