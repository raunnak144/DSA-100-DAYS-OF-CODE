//Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];

    // Read input string
    scanf("%s", s);

    int len = strlen(s);

    // Print in reverse
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }

    return 0;
}

