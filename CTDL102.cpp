#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Khởi tạo ma trận kề
    vector<vector<int>> adjMatrix(n, vector<int>(n));
    
    // Đọc ma trận kề từ đầu vào
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjMatrix[i][j];
        }
    }

    // Chuyển đổi từ ma trận kề sang danh sách kề và in ra kết quả
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            if (adjMatrix[i][j] == 1) {
                cout  << j + 1 << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}