#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<long long>> multiplyMatrix(const vector<vector<long long>>& a, const vector<vector<long long>>& b, int n) {
    vector<vector<long long>> res(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

vector<vector<long long>> matrixPower(vector<vector<long long>>& a, int n, long long k) {
    if (k == 1) return a;
    if (k % 2 == 0) {
        vector<vector<long long>> half = matrixPower(a, n, k / 2);
        return multiplyMatrix(half, half, n);
    }
    return multiplyMatrix(a, matrixPower(a, n, k - 1), n);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<vector<long long>> a(n, vector<long long>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        vector<vector<long long>> ak = matrixPower(a, n, k);
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum = (sum + ak[i][i]) % MOD;

        cout << sum << endl;
    }
    return 0;
}