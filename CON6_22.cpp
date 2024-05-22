#include <iostream>
using namespace std;

// Hàm tìm kiếm nhị phân trả về 1 nếu X có mặt trong mảng, ngược lại trả về -1
int binary_search(int A[], int n, int X) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == X) {
            return 1;
        } else if (A[mid] < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T; // Đọc số lượng bộ test

    while (T--) {
        int n, X;
        cin >> n >> X;
        int A[n];

        // Đọc mảng A
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        // In ra kết quả tìm kiếm nhị phân
        cout << binary_search(A, n, X) << endl;
    }

    return 0;
}