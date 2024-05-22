#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, n;
    cin >> T;
    
    while (T--) {
        cin >> n;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            int queryType;
            cin >> queryType;
            
            switch (queryType) {
                case 1: // Trả về kích thước của queue
                    cout << q.size() << "\n";
                    break;
                case 2: // Kiểm tra xem queue có rỗng không
                    if (q.empty()) {
                        cout << "YES" << "\n";
                    } else {
                        cout << "NO" << "\n";
                    }
                    break;
                case 3: // Thêm phần tử vào cuối queue
                    {
                        int number;
                        cin >> number;
                        q.push(number);
                    }
                    break;
                case 4: // Loại bỏ phần tử đầu queue
                    if (!q.empty()) {
                        q.pop();
                    }
                    break;
                case 5: // Trả về phần tử ở đầu queue
                    if (q.empty()) {
                        cout << "-1" << "\n";
                    } else {
                        cout << q.front() << "\n";
                    }
                    break;
                case 6: // Trả về phần tử cuối queue
                    if (q.empty()) {
                        cout << "-1" << "\n";
                    } else {
                        cout << q.back() << "\n";
                    }
                    break;
                default:
                    // Trường hợp không có truy vấn hợp lệ
                    break;
            }
        }
    }
    
    return 0;
}