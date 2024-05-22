#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Cell {
    int x, y, dist;
};

int minSteps(vector<vector<int>>& matrix, int M, int N) {
    if (matrix.empty() || matrix[0].empty()) return -1;

    vector<vector<bool>> visited(M, vector<bool>(N, false));
    queue<Cell> q;

    // Start from the top-left corner
    q.push({0, 0, 0});
    visited[0][0] = true;

    // Directions for movement: right and down
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};

    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        // If we reach the bottom-right corner
        if (curr.x == M - 1 && curr.y == N - 1) {
            return curr.dist;
        }

        // Explore the next positions
        for (int i = 0; i < 2; ++i) {
            int nx = curr.x + dx[i] * matrix[curr.x][curr.y];
            int ny = curr.y + dy[i] * matrix[curr.x][curr.y];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, curr.dist + 1});
            }
        }
    }

    return -1;  // No path found
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        vector<vector<int>> matrix(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> matrix[i][j];
            }
        }

        int result = minSteps(matrix, M, N);
        cout << result << endl;
    }
    return 0;
}