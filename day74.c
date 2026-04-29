#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][100];

    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int maxCount = 0;
    char result[100];

    for(int i = 0; i < n; i++) {
        int count = 1;

        // count frequency of names[i]
        for(int j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count++;
            }
        }

        // update result
        if(count > maxCount) {
            maxCount = count;
            strcpy(result, names[i]);
        }
        else if(count == maxCount) {
            // lexicographically smaller
            if(strcmp(names[i], result) < 0) {
                strcpy(result, names[i]);
            }
        }
    }

    printf("%s\n", result);

    return 0;
}