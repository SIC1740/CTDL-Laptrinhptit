#include <iostream>
#include <vector>
using namespace std;

// Function to check if a number is valid
bool isValid(int k) {
    bool used[6] = {false};
    while (k > 0) {
        int digit = k % 10;
        if (digit > 5) return false;  // Digits must be 0 to 5
        if (used[digit]) return false;  // Digits must be unique
        used[digit] = true;
        k /= 10;
    }
    return true;
}

// Function to precompute all valid numbers
vector<int> precomputeValidNumbers(int max_range) {
    vector<int> valid_numbers;
    for (int k = 0; k <= max_range; k++) {
        if (isValid(k)) {
            valid_numbers.push_back(k);
        }
    }
    return valid_numbers;
}

// Function to count valid numbers in the given range
int countValidNumbers(int L, int R, const vector<int>& valid_numbers) {
    int count = 0;
    for (int num : valid_numbers) {
        if (num >= L && num <= R) {
            count++;
        }
        if (num > R) break;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    vector<pair<int, int>> queries(T);
    int max_R = 0;

    // Read all queries and determine the maximum R
    for (int i = 0; i < T; i++) {
        cin >> queries[i].first >> queries[i].second;
        max_R = max(max_R, queries[i].second);
    }

    // Precompute valid numbers up to the maximum R found
    vector<int> valid_numbers = precomputeValidNumbers(max_R);

    // Process each query and output the results
    for (const auto& query : queries) {
        cout << countValidNumbers(query.first, query.second, valid_numbers) << endl;
    }

    return 0;
}