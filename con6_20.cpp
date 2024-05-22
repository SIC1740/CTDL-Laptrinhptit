#include <iostream>
#include <vector>

int countPairsWithDifferenceLessThanK(const std::vector<int>& arr, int k) {
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(arr[i] - arr[j]) < k) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    int T;
    std::cin >> T; // Đọc số lượng bộ test

    while (T--) {
        int n, k;
        std::cin >> n >> k; // Đọc số phần tử của mảng và số k
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i]; // Đọc các phần tử của mảng
        }

        std::cout << countPairsWithDifferenceLessThanK(arr, k) << std::endl;
    }

    return 0;
}