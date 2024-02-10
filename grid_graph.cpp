#include "bits/stdc++.h"
using namespace std;

int H, W;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char field[500][500];
bool seen[500][500];
void dfs(int h, int w) {
    seen[h][w] = true;

    for (int i = 0; i < 4; i++) {
        int nh = h + dy[i];
        int nw = w + dx[i];
        
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (field[nh][nw] == '#') continue;

        if (seen[nh][nw]) continue;
        dfs(nh, nw);
    }
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> field[i][j];
        }
    }
    int sh = 0, sw = 0, gh = 0, gw = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (field[i][j] == 's') sh = i, sw = j;
            if (field[i][j] == 'g') gh = i, gw = j;
        }
    }
    memset(seen, 0, sizeof(seen));
    dfs(sh, sw);

    if (seen[gh][gw]) cout << "Yes" << endl;
    else cout << "No" << endl;
}