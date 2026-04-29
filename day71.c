#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100]; // max size

int main() {
    int m, q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    // initialize table
    for(int i = 0; i < m; i++)
        table[i] = EMPTY;

    while(q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        int h = key % m;

        if(strcmp(op, "INSERT") == 0) {
            int i = 0;
            while(i < m) {
                int idx = (h + i*i) % m;
                if(table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
                i++;
            }
        }
        else if(strcmp(op, "SEARCH") == 0) {
            int i = 0, found = 0;
            while(i < m) {
                int idx = (h + i*i) % m;
                if(table[idx] == key) {
                    found = 1;
                    break;
                }
                if(table[idx] == EMPTY) break;
                i++;
            }

            if(found)
                printf("Found\n");
            else
                printf("Not Found\n");
        }
    }

    return 0;
}