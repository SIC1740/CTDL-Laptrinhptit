#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Hàm tính khoảng cách giữa hai điểm
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int T, N;
    cin >> T; // Đọc số lượng bộ test
    while (T--) {
        cin >> N; // Đọc số lượng điểm
        vector<pair<int, int>> points(N);
        for (int i = 0; i < N; ++i) {
            cin >> points[i].first >> points[i].second;
        }

        double minDist = 1e9; // Khởi tạo khoảng cách nhỏ nhất là một giá trị lớn
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                // Tính khoảng cách giữa điểm i và j
                double dist = distance(points[i].first, points[i].second, points[j].first, points[j].second);
                // Cập nhật khoảng cách nhỏ nhất
                if (dist < minDist) {
                    minDist = dist;
                }
            }
        }

        // In ra khoảng cách nhỏ nhất với độ chính xác 6 chữ số sau dấu phẩy
        cout << fixed << setprecision(6) << minDist << " "<< endl;
    }
    return 0;
}