#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <array>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

vector<int> generatePrimes() {
    vector<int> primes;
    for (int i = 1000; i <= 9999; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

vector<vector<int>> buildGraph(const vector<int>& primes) {
    unordered_set<int> primeSet(primes.begin(), primes.end());
    vector<vector<int>> graph(10000);
    for (int prime : primes) {
        string p = to_string(prime);
        for (int i = 0; i < 4; i++) {
            string tmp = p;
            for (char ch = '0'; ch <= '9'; ch++) {
                if (ch != tmp[i]) {
                    tmp[i] = ch;
                    int next = stoi(tmp);
                    if (primeSet.count(next)) {
                        graph[prime].push_back(next);
                    }
                }
            }
        }
    }
    return graph;
}

int bfs(const vector<vector<int>>& graph, int start, int end) {
    if (start == end) return 0;
    queue<pair<int, int>> q; // node, depth
    vector<bool> visited(10000, false);
    q.push({start, 0});
    visited[start] = true;
    
    while (!q.empty()) {
        auto [current, depth] = q.front();
        q.pop();
        
        for (int next : graph[current]) {
            if (next == end) {
                return depth + 1;
            }
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, depth + 1});
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    vector<pair<int, int>> queries(T);
    for (int i = 0; i < T; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<int> primes = generatePrimes();
    vector<vector<int>> graph = buildGraph(primes);

    for (const auto& [start, end] : queries) {
        cout << bfs(graph, start, end) << "\n";
    }
    return 0;
}