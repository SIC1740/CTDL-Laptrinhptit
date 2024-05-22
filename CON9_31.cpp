#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 1001;
vector<int> graph[MAX_N];
bool visited[MAX_N];

// Hàm DFS kiểm tra tính liên thông và phát hiện chu trình
bool dfs(int vertex, int parent) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            if (!dfs(neighbor, vertex))
                return false;
        } else if (neighbor != parent) {
            // Nếu gặp một đỉnh đã thăm không phải là cha của đỉnh hiện tại thì có chu trình
            return false;
        }
    }
    return true;
}

// Kiểm tra đồ thị có phải là cây
string is_tree(int n) {
    if (n == 1)
        return "YES"; // Trường hợp đặc biệt chỉ có 1 đỉnh

    memset(visited, 0, sizeof(visited));

    // Bắt đầu DFS từ đỉnh 1
    if (!dfs(1, -1))
        return "NO"; // Có chu trình

    // Kiểm tra tính liên thông
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            return "NO"; // Nếu có đỉnh chưa thăm, đồ thị không liên thông
    }

    return "YES";
}

int main() {
    int t, n, u, v;
    cin >> t;

    while (t--) {
        cin >> n;
        // Khởi tạo đồ thị
        for (int i = 1; i <= n; ++i)
            graph[i].clear();

        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cout << is_tree(n) << endl;
    }

    return 0;
}