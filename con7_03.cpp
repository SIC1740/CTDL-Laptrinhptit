#include <iostream>
#include <sstream>
#include <string>
#include <algorithm> // Thêm thư viện này để sử dụng hàm reverse

using namespace std;

// Hàm đảo ngược từng từ trong xâu
string reverseWords(const string &str) {
    stringstream ss(str);
    string word, result;
    while (ss >> word) {
        reverse(word.begin(), word.end()); // Đảo ngược từ
        result += word + " "; // Thêm từ vào kết quả
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự newline sau số test

    string str;
    for (int i = 0; i < T; ++i) {
        getline(cin, str); // Đọc mỗi xâu
        cout << reverseWords(str) << endl; // Xuất kết quả sau khi đảo ngược từng từ
    }

    return 0;
}