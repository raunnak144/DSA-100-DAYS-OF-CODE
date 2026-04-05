#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

// Display operation (Top to Bottom)
void display() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int value;
            scanf("%d", &value);
            push(value);
        } 
        else if (type == 2) {
            pop();
        } 
        else if (type == 3) {
            display();
        }
    }

    return 0;
}