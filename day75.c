#include <stdio.h>

#define MAX 1000

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    // Hash map using arrays (simple approach)
    int hash[2 * MAX + 1];
    
    // Initialize with -1
    for (int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -2;   // -2 means not visited

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum = 0
        if (sum == 0) {
            max_len = i + 1;
        }

        // Shift index to handle negative sums
        int index = sum + MAX;

        // Case 2: sum seen before
        if (hash[index] != -2) {
            int prev_index = hash[index];
            if (i - prev_index > max_len)
                max_len = i - prev_index;
        } else {
            // Store first occurrence
            hash[index] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));
    return 0;
}