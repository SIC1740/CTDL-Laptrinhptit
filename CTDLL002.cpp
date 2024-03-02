#include <bits/stdc++.h>
using namespace std;

void printCombinations(string &str, vector<int> &positions, int index) {
    if (index == positions.size()) {
        cout << str << endl;
        return;
    }

    // First, set the current position to '0' and recurse
    str[positions[index]] = '0';
    printCombinations(str, positions, index + 1);

    // Then, set the current position to '1' and recurse
    str[positions[index]] = '1';
    printCombinations(str, positions, index + 1);
}

void implement() {
    string str;
    cin >> str;

    vector<int> positions;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '?') {
            positions.push_back(i);
        }
    }

    printCombinations(str, positions, 0);
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        implement();
    }
    return 0;
}