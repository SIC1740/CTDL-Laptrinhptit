#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeParentheses(const string &expression) {
    string result;
    stack<bool> flip; // Dùng stack để xác định khi nào cần đảo ngược dấu

    for (char ch : expression) {
        if (ch == '(') {
            // Kiểm tra xem dấu trước '(' có phải là '-' hay không
            if (!result.empty() && result.back() == '-') {
                flip.push(true); // Cần đảo ngược các dấu trong ngoặc
            } else {
                flip.push(false); // Chỉ loại bỏ ngoặc mà không đảo ngược
            }
        } else if (ch == ')') {
            // Kết thúc phạm vi đảo ngược dấu
            if (!flip.empty()) flip.pop();
        } else if (ch == '+' || ch == '-') {
            // Kiểm tra và đảo ngược dấu nếu cần
            if (!flip.empty() && flip.top()) {
                result += (ch == '+') ? '-' : '+';
            } else {
                result += ch;
            }
        } else {
            result += ch;
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự newline sau số lượng test

    while (T--) {
        string expression;
        getline(cin, expression); // Đọc biểu thức

        cout << removeParentheses(expression) << endl;
    }

    return 0;
}