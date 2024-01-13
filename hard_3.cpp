#include "bits/stdc++.h"
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    char s[h + 1][w + 1];
    int dp[h + 1][w + 1];
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> s[i][j];
        }
    }
    dp[1][1] = 0;
    if (s[1][1] == '#') dp[1][1]++;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i == 1 && j == 1) continue;
            dp[i][j] = min(dp[i - 1][j]+(s[i - 1][j] == '.' && s[i][j] == '#'), dp[i][j - 1]+(s[i][j - 1] == '.' && s[i][j] == '#'));
        }
    }
    cout << dp[h][w] << endl;
}