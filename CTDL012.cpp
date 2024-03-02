#include <iostream>
#include <queue>
#include <string>
using namespace std;

string findSmallestMultiple(int N) {
    queue<string> q;
    q.push("9");

    while (!q.empty()) {
        string s = q.front(); q.pop();
        long long num = stoll(s);

        if (num % N == 0) {
            return s;
        }

        q.push(s + "0");
        q.push(s + "9");
    }

    return "";
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << findSmallestMultiple(N) << endl;
    }
    return 0;
}