#include "bits/stdc++.h"
using namespace std;
using Graph = vector<vector<int> >;

vector<int> depth;
vector<int> sub_tree;
void dfs(Graph &G, int v, int p, int d) {
    depth[v] = d;
    for (auto nv: G[v]) {
        if (nv == p) continue;
        dfs(G, nv, v, d + 1);
    }

    sub_tree[v] = 1;
    for (auto c: G[v]) {
        sub_tree[v] += sub_tree[c];
    }
}

int main() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    depth.assign(N, 0);
    sub_tree.assign(N, 0);
    dfs(G, 0, -1, 0);
}