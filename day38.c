#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Initialize deque
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

// Check if empty
int empty(Deque *dq) {
    return dq->size == 0;
}

// Check if full
int full(Deque *dq) {
    return dq->size == MAX;
}

// Insert at front
void push_front(Deque *dq, int x) {
    if (full(dq)) {
        printf("Deque is full! Cannot push_front.\n");
        return;
    }

    if (empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }

    dq->arr[dq->front] = x;
    dq->size++;
}

// Insert at back
void push_back(Deque *dq, int x) {
    if (full(dq)) {
        printf("Deque is full! Cannot push_back.\n");
        return;
    }

    if (empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }

    dq->arr[dq->rear] = x;
    dq->size++;
}

// Remove from front
int pop_front(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty! Cannot pop_front.\n");
        return INT_MIN;
    }

    int val = dq->arr[dq->front];

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }

    dq->size--;
    return val;
}

// Remove from back
int pop_back(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty! Cannot pop_back.\n");
        return INT_MIN;
    }

    int val = dq->arr[dq->rear];

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }

    dq->size--;
    return val;
}

// Get front element
int front(Deque *dq) {
    return empty(dq) ? INT_MIN : dq->arr[dq->front];
}

// Get rear element
int back(Deque *dq) {
    return empty(dq) ? INT_MIN : dq->arr[dq->rear];
}

// Display deque
void display(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque: ");
    int i = dq->front;

    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    display(&dq);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));

    pop_front(&dq);
    display(&dq);

    pop_back(&dq);
    display(&dq);

    return 0;
}