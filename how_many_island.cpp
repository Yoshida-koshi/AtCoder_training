#include "bits/stdc++.h"
using namespace std;

int W, H;
int field[100][100];
void dfs(int h, int w) {
    field[h][w] = 0;
    
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            int nh = h + dy;
            int nw = w + dx;

            if (nh < 0 || nh >= H || nw < 0 || nh >= W) continue;
            if (field[nh][nw] == 0) continue;

            dfs(nh, nw);
        }
    }
}

int main() {
    while (true) {
        int result = 0;
        cin >> W >> H;
        if (W == 0 && H == 0) break;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> field[i][j];
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (field[i][j] == 0) continue;
                dfs(i, j);
                result++;
            }
        }
        cout << result << endl;
    } 
}