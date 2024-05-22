#include <iostream>
#include <vector>
#include <algorithm>

void find_k_largest_elements(int N, int K, std::vector<int>& A) {
    std::sort(A.begin(), A.end(), std::greater<int>()); // Sắp xếp mảng giảm dần
    for (int i = 0; i < K; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int T, N, K;
    std::cin >> T; // Đọc số lượng bộ test

    for (int t = 0; t < T; ++t) {
        std::cin >> N >> K;
        std::vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        find_k_largest_elements(N, K, A);
    }

    return 0;
}