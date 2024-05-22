#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <cmath>

int min_operations_to_one(int N) {
    if (N == 1) return 0;

    std::queue<std::pair<int, int>> queue; // Pair (current value, steps)
    std::unordered_set<int> visited;

    queue.push({N, 0});
    visited.insert(N);

    while (!queue.empty()) {
        auto [current, steps] = queue.front();
        queue.pop();

        // Operation (a)
        if (current - 1 == 1) {
            return steps + 1;
        }
        if (current - 1 > 1 && visited.find(current - 1) == visited.end()) {
            queue.push({current - 1, steps + 1});
            visited.insert(current - 1);
        }

        // Operation (b)
        for (int i = 2; i <= sqrt(current); ++i) {
            if (current % i == 0) {
                int max_factor = std::max(i, current / i);
                if (max_factor == 1) {
                    return steps + 1;
                }
                if (visited.find(max_factor) == visited.end()) {
                    queue.push({max_factor, steps + 1});
                    visited.insert(max_factor);
                }
            }
        }
    }

    return -1; // This should not happen for N >= 1
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;
        std::cout << min_operations_to_one(N) << std::endl;
    }

    return 0;
}