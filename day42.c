#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int stack[MAX];
int top = -1;

// Queue operations
void enqueue(int x) {
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;

    return queue[front++];
}

// Stack operations
void push(int x) {
    if (top == MAX - 1)
        return;

    stack[++top] = x;
}

int pop() {
    if (top == -1)
        return -1;

    return stack[top--];
}

int main() {
    int n, x;

    scanf("%d", &n);

    // Input queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    for (int i = 0; i < n; i++) {
        push(dequeue());
    }

    // Step 2: Stack → Queue
    for (int i = 0; i < n; i++) {
        enqueue(pop());
    }

    // Print reversed queue
    while (front <= rear) {
        printf("%d ", dequeue());
    }

    return 0;
}