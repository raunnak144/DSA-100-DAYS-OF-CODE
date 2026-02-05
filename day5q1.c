// A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.
#include <stdio.h>

int main() {
    int n, m;

    // Input sizes
    printf("Enter number of entries in Server 1 log: ");
    scanf("%d", &n);

    printf("Enter number of entries in Server 2 log: ");
    scanf("%d", &m);

    int A[n], B[m], C[n + m];

    // Input first log
    printf("Enter Server 1 log (sorted):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Input second log
    printf("Enter Server 2 log (sorted):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    int i = 0, j = 0, k = 0;

    // Merge both logs
    while (i < n && j < m) {
        if (A[i] <= B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }

    // Copy remaining elements
    while (i < n) {
        C[k++] = A[i++];
    }

    while (j < m) {
        C[k++] = B[j++];
    }

    // Output merged log
    printf("\nMerged chronological log:\n");
    for (i = 0; i < n + m; i++) {
        printf("%d ", C[i]);
    }

    return 0;
}
