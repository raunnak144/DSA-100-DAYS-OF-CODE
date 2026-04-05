#include <stdio.h>
#include <stdlib.h>

// Structure of Linked List Node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create linked list
struct Node* createList(int n)
{
    struct Node *head = NULL, *temp, *newNode;
    int value;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head==NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// Function to count nodes
int length(struct Node *head)
{
    int count=0;

    while(head!=NULL)
    {
        count++;
        head=head->next;
    }

    return count;
}

// Function to find intersection
void findIntersection(struct Node *head1, struct Node *head2)
{
    int len1 = length(head1);
    int len2 = length(head2);

    int diff;

    if(len1>len2)
    {
        diff = len1-len2;

        while(diff--)
            head1=head1->next;
    }
    else
    {
        diff = len2-len1;

        while(diff--)
            head2=head2->next;
    }

    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data == head2->data)
        {
            printf("%d",head1->data);
            return;
        }

        head1=head1->next;
        head2=head2->next;
    }

    printf("No Intersection");
}

// Main Function
int main()
{
    int n,m;

    scanf("%d",&n);
    struct Node *head1 = createList(n);

    scanf("%d",&m);
    struct Node *head2 = createList(m);

    findIntersection(head1,head2);

    return 0;
}