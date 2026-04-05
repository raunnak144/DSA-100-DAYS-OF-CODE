#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
void insertNode(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print polynomial in standard form
void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->coeff);
        if (temp->exp != 0) {
            printf("x^%d", temp->exp);
        }
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, coeff, exp;
    struct Node* poly = NULL;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertNode(&poly, coeff, exp);
    }

    // Output
    printPolynomial(poly);

    return 0;
}