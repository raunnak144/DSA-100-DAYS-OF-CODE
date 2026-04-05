#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, i, x;
    struct Node *head = NULL, *temp = NULL, *newnode = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Make Circular
    temp->next = head;

    // Traversal
    temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    return 0;
}