#include "bits/stdc++.h"
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char field[20][20];
char copy_field[20][20];
void dfs(int h, int w) {
    copy_field[h][w] = 'x';

    for (int i = 0; i < 4; i++) {
        int nh = h + dy[i];
        int nw = w + dx[i];

        if (nh < 0 || nh >= 10 || nw < 0 || nw >= 10) continue;
        if (copy_field[nh][nw] == 'x') continue;

        dfs(nh, nw);
    }
}

void make_copy_field() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            copy_field[i][j] = field[i][j];
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> field[i][j];
        }
    }

    make_copy_field();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (field[i][j] == 'x') copy_field[i][j] = 'o';
            else continue;
            int result = 0;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (copy_field[i][j] == 'x') continue;
                    dfs(i, j);
                    result++;
                }
            }
            if (result == 1) {
                cout << "YES" << endl;
                return 0;
            } else {
                make_copy_field();
            }
        }
    }

    cout << "NO" << endl;
}