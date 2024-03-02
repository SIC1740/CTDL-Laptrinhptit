#include <iostream>
using namespace std;

long long maxBishops(long long n) {
    // Vì mỗi quân tượng chiếm 1 đường chéo, và mỗi bàn cờ có 2n-1 đường chéo,
    // nhưng chỉ có thể sử dụng nửa số đó một cách hiệu quả do cách tấn công của tượng.
    // Do đó, công thức tính số tượng tối đa là n + (n - 1) = 2n - 1.
    // Nhưng để tránh đặt tượng ở các ô không an toàn, chúng ta cần phân tích kỹ hơn.
    if (n == 1) return 1; // Trường hợp đặc biệt khi n = 1, chỉ có thể đặt 1 quân tượng
    return 2*(n-1); // Trả về số lượng tượng tối đa có thể đặt mà không tấn công lẫn nhau
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        cout << maxBishops(n) << endl;
    }
    return 0;
}