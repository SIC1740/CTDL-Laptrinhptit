#include <iostream>
#include <string>
#include <stack>

using namespace std;

string normalizeExpression(const string& expr) {
    string normalized;
    stack<int> signs;
    int sign = 1;  // Start with a positive sign context

    for (int i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        if (c == '(') {
            // Check the character before '(' for sign context
            if (i > 0 && expr[i-1] == '-') {
                signs.push(-sign);
                sign *= -1;
            } else {
                signs.push(sign);
            }
        } else if (c == ')') {
            // Restore the sign context after leaving a parenthesis
            if (!signs.empty()) {
                sign = signs.top();
                signs.pop();
            }
        } else if (c == '+' || c == '-') {
            // Convert the sign based on the current context
            if (sign == -1) {
                normalized += (c == '+') ? '-' : '+';
            } else {
                normalized += c;
            }
        } else {
            // Append operands and other characters
            normalized += c;
        }
    }
    return normalized;
}

bool compareExpressions(const string& P1, const string& P2) {
    string normP1 = normalizeExpression(P1);
    string normP2 = normalizeExpression(P2);
    return normP1 == normP2;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();  // To ignore the newline after reading T

    while (T--) {
        string P1, P2;
        getline(cin, P1);
        getline(cin, P2);

        if (compareExpressions(P1, P2)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}