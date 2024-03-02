#include <iostream>
#include <algorithm> // Cho next_permutation
using namespace std;

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        int arr[N];

        // Khởi tạo mảng với các số từ 1 đến N
        for (int i = 0; i < N; ++i) {
            arr[i] = i + 1;
        }

        // Sử dụng next_permutation để liệt kê tất cả các hoán vị
        do {
            for (int i = 0; i < N; ++i) {
                cout << arr[i];
            }
            cout << " ";
        } while (next_permutation(arr, arr + N));
        
        cout << endl;
    }
    return 0;
}