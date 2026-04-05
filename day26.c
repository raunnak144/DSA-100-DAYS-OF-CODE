#include <stdio.h>
#include <stdlib.h>

// Structure of Doubly Linked List Node
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Insert node at end
struct Node* insertEnd(struct Node* head, int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    // If list is empty
    if(head == NULL)
        return newNode;

    temp = head;

    // Move to last node
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Traverse and print
void traverse(struct Node* head)
{
    struct Node* temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, x;
    struct Node* head = NULL;

    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    traverse(head);

    return 0;
}