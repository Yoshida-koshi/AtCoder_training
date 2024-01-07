#include "bits/stdc++.h"
using namespace std;

int dp[33][100000];
int ans[100000];

int main() {
    string s;
    cin >> s;
    int sNum = s.length();
    for (int i = 0; i < sNum; i++) {
        if (s[i] == 'R') dp[0][i] = i + 1;
        else dp[0][i] = i - 1;
    }

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < sNum; j++) {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }
    for (int i = 0; i < sNum; i++) {
        ans[dp[32][i]]++;
    }
    for (int i = 0; i < sNum; i++) {
        if (i == sNum - 1) {
            cout << ans[i] << endl;
        } else {
            cout << ans[i] << " ";
        }
    }
}