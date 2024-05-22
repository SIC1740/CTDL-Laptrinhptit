#include <iostream>
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void find_prime_pair(int N) {
    for (int i = 2; i <= N / 2; i++) {
        if (is_prime(i) && is_prime(N - i)) {
            std::cout << i << " " << N - i << std::endl;
            return;
        }
    }
    std::cout << "-1" << std::endl; // Nếu không tìm được cặp số nguyên tố
}

int main() {
    int T, N;
    std::cin >> T;

    while (T--) {
        std::cin >> N;
        find_prime_pair(N);
    }

    return 0;
}