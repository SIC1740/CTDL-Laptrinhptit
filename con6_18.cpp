#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> merge_and_sort_arrays(const std::vector<int>& A, const std::vector<int>& B) {
    std::vector<int> C;
    C.reserve(A.size() + B.size());

    // Hợp nhất hai mảng
    C.insert(C.end(), A.begin(), A.end());
    C.insert(C.end(), B.begin(), B.end());

    // Sắp xếp mảng hợp nhất
    std::sort(C.begin(), C.end());

    return C;
}

int main() {
    int T, n, m;
    std::cin >> T;

    while (T--) {
        std::cin >> n >> m;
        std::vector<int> A(n);
        std::vector<int> B(m);

        for (int i = 0; i < n; i++) {
            std::cin >> A[i];
        }

        for (int i = 0; i < m; i++) {
            std::cin >> B[i];
        }

        std::vector<int> C = merge_and_sort_arrays(A, B);

        for (int num : C) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}