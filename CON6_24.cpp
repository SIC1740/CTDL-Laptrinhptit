#include <iostream>
#include <vector>
using namespace std;

int binarySearchRotated(const vector<int>& arr, int x) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        // Xác định nửa sắp xếp tăng dần
        if (arr[start] <= arr[mid]) {
            // Kiểm tra x có nằm trong phạm vi tăng dần hay không
            if (x >= arr[start] && x < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            // Kiểm tra x có nằm trong phạm vi tăng dần hay không
            if (x > arr[mid] && x <= arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1; // Nếu không tìm thấy x trong mảng
}

int main() {
    int T, n, x;
    cin >> T;

    while (T--) {
        cin >> n >> x;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int result = binarySearchRotated(arr, x);
        cout << result +1 << endl;
    }

    return 0;
}