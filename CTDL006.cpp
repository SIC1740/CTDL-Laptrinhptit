#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Hàm này sẽ in ra một hoán vị
void printPermutation(const vector<int>& permutation) {
    for (int num : permutation) {
        cout << num;
    }
    cout << " ";
}

// Hàm chính để sinh hoán vị
void generatePermutations(int N) {
    vector<int> permutation;
    
    // Tạo hoán vị đầu tiên với các số theo thứ tự giảm dần
    for (int i = N; i >= 1; --i) {
        permutation.push_back(i);
    }

    // Sử dụng hàm next_permutation để sinh ra các hoán vị tiếp theo
    do {
        printPermutation(permutation);
    } while (prev_permutation(permutation.begin(), permutation.end()));
}

int main() {
    int T, N;
    cin >> T; // Đọc số lượng test cases

    while (T--) {
        cin >> N; // Đọc giá trị N cho mỗi test case
        generatePermutations(N);
        cout << endl;
    }

    return 0;
}