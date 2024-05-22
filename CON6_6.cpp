#include <iostream>
#include <vector>

using namespace std;

// Hàm để sắp xếp mảng
void sort012(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main() {
    int T, n;
    cin >> T; // Đọc số lượng bộ test
    while (T--) {
        cin >> n; // Đọc số phần tử của mảng
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i]; // Đọc các phần tử của mảng
        }

        // Sắp xếp mảng
        sort012(arr);

        // In kết quả
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}