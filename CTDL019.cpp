#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm tìm và in ra hoán vị tiếp theo
void nextPermutation(vector<int> &arr) {
    int n = arr.size(), i, j;

    // Tìm pivot
    for (i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            break;
        }
    }

    // Nếu tìm thấy pivot, tìm phần tử để đổi chỗ
    if (i >= 0) {
        for (j = n - 1; j > i; j--) {
            if (arr[j] > arr[i]) {
                break;
            }
        }
        swap(arr[i], arr[j]);
    }

    // Đảo ngược đoạn sau pivot
    reverse(arr.begin() + i + 1, arr.end());

    // In kết quả
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        nextPermutation(arr);
    }

    return 0;
}