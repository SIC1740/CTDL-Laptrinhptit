#include <iostream>
#include <bitset>
#include <sstream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        stringstream output;  // Dùng để xây dựng chuỗi đầu ra
        for (int i = 1; i <= n; ++i) {
            output << bitset<16>(i).to_string().substr(bitset<16>(i).to_string().find('1')) << " ";
        }
        cout << output.str() << endl; // In chuỗi và bỏ các khoảng trắng thừa ở cuối
    }
    return 0;
}