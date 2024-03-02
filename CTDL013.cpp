#include <iostream>
#include <vector>

using namespace std;

void printSubset(vector<int>& subset) {
    for (int i = 0; i < subset.size(); ++i) {
        cout << subset[i];
    }
    cout << " ";
}

void findSubsets(int n, int k, int start, vector<int>& subset) {
    if (subset.size() == k) {
        printSubset(subset);
        return;
    }

    for (int i = start; i <= n; ++i) {
        subset.push_back(i);
        findSubsets(n, k, i + 1, subset);
        subset.pop_back(); // backtrack
    }
}

int main() {
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> subset;
        findSubsets(N, K, 1, subset);
        cout << endl;
    }
    return 0;
}