// TÌM SỐ THÀNH PHẦN LIÊN THÔNG VỚI BFS

#include <bits/stdc++.h>
using namespace std;

int V, E, u, v, lthong;
vector<vector<int>> G;
vector<bool> vs;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vs[s] = 1;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int v : G[u]) {
            if (!vs[v]) {
                vs[v] = 1;
                q.push(v);
            }
        }
    }
}

void testCase() {
    lthong = 0;
    cin >> V >> E;
    G.clear(); G.resize(V + 1);
    vs.clear(); vs.resize(V + 1, 0);
    while (E--) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= V; ++i) {
        if (!vs[i]) {
            bfs(i);
            lthong++;
        }
    }
    cout << lthong;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 1; cin >> T;
    while (T--) {
        testCase();
        cout << "\n";
    }
    return 0;
}