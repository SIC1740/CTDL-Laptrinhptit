#include <iostream>
#include <vector>
using namespace std;

// Hàm để in một xâu
void printString(const vector<char>& str) {
    for (char ch : str) {
        cout << ch;
    }
    cout << " ";
}

// Hàm quay lui để tạo xâu
void generateString(int n, vector<char>& str, int len) {
    if (len == n) { // Khi đạt đủ độ dài, in xâu
        printString(str);
        return;
    }

    // Thêm 'A' vào xâu và quay lui
    str[len] = 'A';
    generateString(n, str, len + 1);

    // Thêm 'B' vào xâu và quay lui
    str[len] = 'B';
    generateString(n, str, len + 1);
}

int main() {
    int T, n;
    cin >> T; // Đọc số lượng test cases

    while (T--) {
        cin >> n; // Đọc độ dài xâu
        vector<char> str(n); // Tạo xâu với độ dài n

        generateString(n, str, 0); // Gọi hàm quay lui
        cout << endl;
    }

    return 0;
}