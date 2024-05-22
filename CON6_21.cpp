#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void sortByFrequency(std::vector<int>& arr) {
    std::unordered_map<int, int> frequency;
    for (int num : arr) {
        frequency[num]++;
    }

    // Sắp xếp mảng
    std::sort(arr.begin(), arr.end(), 
        [&frequency](int a, int b) {
            if (frequency[a] == frequency[b])
                return a < b; // Nếu số lần xuất hiện bằng nhau, số nhỏ hơn đứng trước
            return frequency[a] > frequency[b]; // Số xuất hiện nhiều lần nhất đứng trước
        }
    );
}

int main() {
    int T;
    std::cin >> T; // Đọc số lượng bộ test

    while (T--) {
        int n;
        std::cin >> n; // Đọc số phần tử của mảng
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i]; // Đọc các phần tử của mảng
        }

        sortByFrequency(arr);

        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}