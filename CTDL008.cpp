#include <iostream>
#include <string>
using namespace std;

// Hàm chuyển đổi mã nhị phân sang mã Gray
string binaryToGray(string binary) {
    string gray = "";

    // Bit đầu tiên của mã Gray giống với bit đầu tiên của số nhị phân
    gray += binary[0];

    // Thực hiện phép XOR cho các bit tiếp theo
    for (int i = 1; i < binary.length(); i++) {
        gray += ((binary[i - 1] == binary[i]) ? '0' : '1');
    }

    return gray;
}

int main() {
    int T;
    cin >> T; // Số lượng test cases

    while (T--) {
        string binary;
        cin >> binary; // Đọc số nhị phân

        // In ra mã Gray tương ứng
        cout << binaryToGray(binary) << endl;
    }

    return 0;
}