#include <iostream>
#include <vector>
#include <limits>

int main() {
    int T, n, m;
    std::cin >> T; // Đọc số lượng test cases

    for (int t = 0; t < T; t++) {
        std::cin >> n >> m; // Đọc số lượng phần tử của mảng A và B

        std::vector<int> A(n), B(m);
        int max_A = std::numeric_limits<int>::min(); // Giá trị nhỏ nhất cho int
        int min_B = std::numeric_limits<int>::max(); // Giá trị lớn nhất cho int

        // Đọc và tìm giá trị lớn nhất trong mảng A
        for (int i = 0; i < n; i++) {
            std::cin >> A[i];
            if (A[i] > max_A) max_A = A[i];
        }

        // Đọc và tìm giá trị nhỏ nhất trong mảng B
        for (int i = 0; i < m; i++) {
            std::cin >> B[i];
            if (B[i] < min_B) min_B = B[i];
        }

        // Tính và in ra tích của phần tử lớn nhất trong A và phần tử nhỏ nhất trong B
        std::cout << max_A * min_B << std::endl;
    }

    return 0;
}