#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top = -1;

/* Push Operation */
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

/* Pop Operation */
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

/* Display Stack (Top to Bottom) */
void display() {
    if (top == -1) {
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    display();

    return 0;
}