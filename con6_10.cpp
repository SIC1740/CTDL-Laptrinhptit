#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

void extract_and_sort_unique_digits(const vector<int>& arr) {
    set<int> digits;
    for (int number : arr) {
        while (number > 0) {
            digits.insert(number % 10);
            number /= 10;
        }
    }

    for (int digit : digits) {
        cout << digit << " ";
    }
    cout << endl;
}

int main() {
    int T, n;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        extract_and_sort_unique_digits(arr);
    }
    return 0;
}