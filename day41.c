#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if(front == NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}

int dequeue(){
    if(front == NULL){
        return -1;
    }

    struct node* temp = front;
    int value = temp->data;

    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    free(temp);
    return value;
}

int main(){
    int n;
    scanf("%d",&n);

    char op[10];
    int x;

    for(int i=0;i<n;i++){
        scanf("%s",op);

        if(op[0]=='E'){     // ENQUEUE
            scanf("%d",&x);
            enqueue(x);
        }
        else{               // DEQUEUE
            printf("%d\n",dequeue());
        }
    }

    return 0;
}