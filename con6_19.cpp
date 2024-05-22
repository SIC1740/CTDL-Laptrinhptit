#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

int countMissingElements(const std::vector<int>& arr) {
    int L = *min_element(arr.begin(), arr.end());
    int R = *max_element(arr.begin(), arr.end());
    std::set<int> uniqueElements(arr.begin(), arr.end());
    
    return (R - L + 1) - uniqueElements.size();
}

int main() {
    int T, n;
    std::cin >> T; // Đọc số lượng bộ test

    while (T--) {
        std::cin >> n; // Đọc số lượng phần tử của mảng
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i]; // Đọc các phần tử của mảng
        }

        std::cout << countMissingElements(arr) << std::endl;
    }

    return 0;
}