// Delete an Element from an Array

#include <stdio.h>

int main() {
    int arr[100], n, pos, i;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position to delete
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    // Check valid position
    if(pos < 1 || pos > n) {
        printf("Invalid position!");
        return 0;
    }

    // Shift elements
    for(i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--; // reduce size

    // Print updated array
    printf("Array after deletion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
