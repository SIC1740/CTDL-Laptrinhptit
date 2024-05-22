#include <iostream>
#include <unordered_map>
using namespace std;

int countPairsWithSum(int A[], int n, int k) {
    unordered_map<int, int> countMap;  // Lưu trữ số lần xuất hiện của mỗi phần tử
    int countPairs = 0;  // Đếm số cặp có tổng bằng k

    // Đếm số lần xuất hiện của mỗi phần tử trong mảng
    for (int i = 0; i < n; i++) {
        countMap[A[i]]++;
    }

    // Tìm kiếm các cặp có tổng bằng k
    for (int i = 0; i < n; i++) {
        countPairs += countMap[k - A[i]];  // Tăng bộ đếm nếu tìm thấy cặp

        // Nếu cặp bao gồm hai số giống nhau, giảm bộ đếm
        if (k - A[i] == A[i]) {
            countPairs--;
        }
    }

    // Mỗi cặp được đếm hai lần, nên cần chia đôi kết quả
    return countPairs / 2;
}

int main() {
    int T, n, k;
    cin >> T;  // Đọc số lượng test cases

    while (T--) {
        cin >> n >> k;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        cout << countPairsWithSum(A, n, k) << endl;
    }

    return 0;
}