#include <iostream>
#include <vector>
#include <algorithm>

int find_first_occurrence(const std::vector<int>& A, int X) {
    int low = 0, high = A.size() - 1;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == X) {
            result = mid;
            high = mid - 1; // Tìm kiếm tiếp trong nửa đầu để tìm phần tử đầu tiên
        } else if (A[mid] > X) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int find_last_occurrence(const std::vector<int>& A, int X) {
    int low = 0, high = A.size() - 1;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == X) {
            result = mid;
            low = mid + 1; // Tìm kiếm tiếp trong nửa sau để tìm phần tử cuối cùng
        } else if (A[mid] > X) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int count_occurrences(const std::vector<int>& A, int X) {
    int first = find_first_occurrence(A, X);
    if (first == -1) {
        return -1; // X không tồn tại trong mảng
    }
    int last = find_last_occurrence(A, X);
    return last - first + 1;
}

int main() {
    int T, N, X;
    std::cin >> T;

    while (T--) {
        std::cin >> N >> X;
        std::vector<int> A(N);

        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
        }

        int count = count_occurrences(A, X);
        std::cout << count << std::endl;
    }

    return 0;
}