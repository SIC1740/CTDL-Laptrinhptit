#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>

// Hàm để tìm số BDN nhỏ nhất chia hết cho N
std::string findSmallestBDN(int N) {
    std::queue<std::pair<std::string, int>> q;
    std::unordered_set<int> visited;

    // Khởi tạo với số 1
    q.push({"1", 1 % N});
    visited.insert(1 % N);

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        std::string currentNum = front.first;
        int mod = front.second;

        // Kiểm tra nếu số hiện tại chia hết cho N
        if (mod == 0) {
            return currentNum;
        }

        // Sinh số mới bằng cách thêm '0' và '1'
        std::string nextNum0 = currentNum + "0";
        std::string nextNum1 = currentNum + "1";
        int mod0 = (mod * 10) % N;
        int mod1 = (mod * 10 + 1) % N;

        // Thêm vào hàng đợi nếu chưa từng thăm
        if (visited.find(mod0) == visited.end()) {
            q.push({nextNum0, mod0});
            visited.insert(mod0);
        }
        if (visited.find(mod1) == visited.end()) {
            q.push({nextNum1, mod1});
            visited.insert(mod1);
        }
    }
    return "";  // Chỉ là dòng lệnh bổ sung để đảm bảo sự an toàn, lý thuyết không bao giờ đến đây
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;
        std::cout << findSmallestBDN(N) << std::endl;
    }

    return 0;
}