#include <bits/stdc++.h>
#include <stdlib.h> /* for abs() */
#include <iostream>

using namespace std;

void minAbsSumPair(int arr[], int arr_size) {
    if (arr_size < 2) {
        cout << "Invalid Input";
        return;
    }

    int min_l = 0, min_r = 1;
    int min_sum = arr[0] + arr[1];
    
    for (int l = 0; l < arr_size - 1; l++) {
        for (int r = l + 1; r < arr_size; r++) {
            int sum = arr[l] + arr[r];
            if (abs(min_sum) > abs(sum)) {
                min_sum = sum;
                min_l = l;
                min_r = r;
            }
        }
    }
    cout  << arr[min_l] + arr[min_r] << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        minAbsSumPair(arr, n);
    }
    
    return 0;
}