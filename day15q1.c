//Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;
    int limit = (m < n) ? m : n;  // handle non-square case safely

    for(int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    printf("%d", sum);

    return 0;
}
