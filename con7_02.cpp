#include <iostream>
#include <stack>

using namespace std;

int main() {
    int Q;
    cin >> Q;  // Đọc số lượng truy vấn
    stack<int> s;
    string command;
    int x;

    for (int i = 0; i < Q; ++i) {
        cin >> command;
        if (command == "PUSH") {
            cin >> x;
            s.push(x);
        } else if (command == "POP") {
            if (!s.empty()) {
                s.pop();
            }
        } else if (command == "PRINT") {
            if (s.empty()) {
                cout << "NONE" << endl;
            } else {
                cout << s.top() << endl;
            }
        }
    }

    return 0;
}