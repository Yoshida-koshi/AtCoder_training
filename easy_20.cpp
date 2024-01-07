#include "bits/stdc++.h"
using namespace std;

int collaz(int n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3 * n + 1;
    }
}

int main() {
    int s;
    int result[1000000];
    int result_collaz;
    cin >> s;
    result[0] = s;
    for (int i = 0; i < 1000000; i++) {
        if (i == 0) {
            result_collaz = collaz(s);
            result[i + 1] = result_collaz;
        } else {
            result_collaz = collaz(result[i]);
            for (int j = 0; j < i; j++) {
                if (result[j] == result_collaz) {
                    cout << i + 2 << endl;
                    return 0;
                }
            }
            result[i + 1] = result_collaz;
            
        }
    }
}