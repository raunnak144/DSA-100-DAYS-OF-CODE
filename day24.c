#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp, *newNode;
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to delete first occurrence
struct Node* deleteKey(struct Node* head, int key) {

    struct Node *temp = head, *prev = NULL;

    // If key is at head
    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search key
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key found
    if(temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }

    return head;
}

// Function to print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {

    int n, key;
    
    scanf("%d", &n);

    struct Node* head = createList(n);

    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}