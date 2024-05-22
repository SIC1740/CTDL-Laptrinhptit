#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

string findSmallestMultiple(int N) {
    queue<pair<string, int>> q; // Queue stores pairs of the number string and its remainder when divided by N
    unordered_set<int> visited; // To avoid processing the same remainder multiple times
    
    // Start with the number "9"
    string initial = "9";
    int rem = 9 % N;
    if (rem == 0) return initial;
    q.push({initial, rem});
    visited.insert(rem);

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        
        // Generate new numbers by appending '0' and '9' to the current number
        vector<string> nextNumbers = {current.first + "0", current.first + "9"};
        for (string nextNumber : nextNumbers) {
            int nextRem = (current.second * 10 + (nextNumber.back() - '0')) % N;
            if (nextRem == 0) {
                return nextNumber;
            }
            if (visited.find(nextRem) == visited.end()) {
                q.push({nextNumber, nextRem});
                visited.insert(nextRem);
            }
        }
    }
    return ""; // This line should never be reached
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << findSmallestMultiple(N) << endl;
    }
    return 0;
}