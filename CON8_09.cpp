#include <iostream>
#include <queue>
#include <vector>
#include <utility> // For std::pair

using namespace std;

int minOperations(int S, int T) {
    if (S == T) return 0;

    queue<pair<int, int>> q;
    vector<bool> visited(20000, false); // Array to keep track of visited numbers

    q.push({S, 0});
    visited[S] = true;

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        // Operations
        int subtracted = current - 1;
        int doubled = current * 2;

        // Check each operation
        if (subtracted == T || doubled == T) {
            return steps + 1;
        }

        if (subtracted > 0 && !visited[subtracted]) {
            visited[subtracted] = true;
            q.push({subtracted, steps + 1});
        }

        if (doubled < 20000 && !visited[doubled]) {
            visited[doubled] = true;
            q.push({doubled, steps + 1});
        }
    }

    return -1; // In case no solution found, which should not happen here
}

int main() {
    int nTests;
    cin >> nTests;
    vector<int> results(nTests);

    for (int i = 0; i < nTests; ++i) {
        int S, T;
        cin >> S >> T;
        results[i] = minOperations(S, T);
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}