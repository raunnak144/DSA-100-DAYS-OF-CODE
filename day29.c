#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, k, i, x;
    struct Node *head = NULL, *temp = NULL, *newnode = NULL;
    struct Node *tail = NULL;

    // Input size
    scanf("%d", &n);

    // Create Linked List
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    scanf("%d", &k);

    // Make k within range
    k = k % n;

    if(k > 0)
    {
        // Make circular
        tail->next = head;

        // Move to (n-k)th node
        temp = head;
        for(i = 1; i < n-k; i++)
        {
            temp = temp->next;
        }

        // New head
        head = temp->next;

        // Break circular
        temp->next = NULL;
    }

    // Print List
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}