#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // Tăng tốc độ nhập/xuất chuẩn
    cin.tie(nullptr);

    int Q;
    cin >> Q; // Đọc số lượng truy vấn
    
    queue<int> q;
    string command;
    int x;

    for (int i = 0; i < Q; ++i) {
        cin >> command; // Đọc loại truy vấn
        
        if (command == "PUSH") {
            cin >> x; // Đọc giá trị x để thêm vào queue
            q.push(x);
        } else if (command == "PRINTFRONT") {
            if (q.empty()) {
                cout << "NONE\n";
            } else {
                cout << q.front() << "\n"; // In phần tử đầu tiên
            }
        } else if (command == "POP") {
            if (!q.empty()) {
                q.pop(); // Xóa phần tử đầu tiên nếu queue không rỗng
            }
        }
    }

    return 0;
}