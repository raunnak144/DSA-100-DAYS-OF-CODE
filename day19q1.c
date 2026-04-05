#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void closestToZero(int arr[], int n) {
    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = 1000000000; // large value
    int x = 0, y = 0;

    // Step 2: Two pointer approach
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            x = arr[left];
            y = arr[right];
        }

        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    // Output result
    printf("%d %d\n", x, y);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    closestToZero(arr, n);

    return 0;
}