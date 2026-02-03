//Linear Search with Comparison Count
#include <stdio.h>

int linearSearch(int arr[], int n, int key, int *count) {
    int i;
    *count = 0;

    for (i = 0; i < n; i++) {
        (*count)++;          // count comparison
        if (arr[i] == key) {
            return i;        // element found
        }
    }
    return -1;               // element not found
}

int main() {
    int n, key, i, index, count;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    index = linearSearch(arr, n, key, &count);

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    printf("Total comparisons: %d\n", count);

    return 0;
}
