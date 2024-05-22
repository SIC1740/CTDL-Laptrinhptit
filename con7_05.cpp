#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<int> longest_valid_parentheses(const vector<string>& test_cases) {
    vector<int> results;

    for (const auto& s : test_cases) {
        stack<int> stack;
        stack.push(-1);  // Initial index for valid substring calculation
        int max_length = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (!stack.empty()) {
                    max_length = max(max_length, i - stack.top());
                } else {
                    stack.push(i);  // Update the base for the next valid substring
                }
            }
        }

        results.push_back(max_length);
    }

    return results;
}

int main() {
    int T;
    cin >> T;
    vector<string> test_cases(T);

    for (int i = 0; i < T; i++) {
        cin >> test_cases[i];
    }

    auto results = longest_valid_parentheses(test_cases);

    for (int length : results) {
        cout << length << endl;
    }

    return 0;
}