#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} NODE;


// Create a node
NODE* createNode(int data) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}


// Insert at beginning
NODE* insertFront(NODE *head, int data) {

    NODE *newNode = createNode(data);

    if(head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }

    return newNode;
}


// Insert at end
NODE* insertEnd(NODE *head, int data) {

    NODE *newNode = createNode(data);

    if(head == NULL)
        return newNode;

    NODE *temp = head;

    while(temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}


// Delete from beginning
NODE* deleteFront(NODE *head) {

    if(head == NULL)
        return NULL;

    NODE *temp = head;

    head = head->next;

    if(head)
        head->prev = NULL;

    free(temp);

    return head;
}


// Delete from end
NODE* deleteEnd(NODE *head) {

    if(head == NULL)
        return NULL;

    NODE *temp = head;

    while(temp->next)
        temp = temp->next;

    if(temp->prev)
        temp->prev->next = NULL;
    else
        head = NULL; // only one node

    free(temp);

    return head;
}


// Display forward
void display(NODE *head) {

    NODE *temp = head;

    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


// Display reverse
void reverseDisplay(NODE *head) {

    if(head == NULL)
        return;

    NODE *temp = head;

    while(temp->next)
        temp = temp->next;

    while(temp) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}


int main() {

    NODE *head = NULL;

    head = insertFront(head, 20);
    head = insertFront(head, 10);
    head = insertEnd(head, 30);

    printf("Forward: ");
    display(head);

    printf("Reverse: ");
    reverseDisplay(head);

    head = deleteFront(head);
    head = deleteEnd(head);

    printf("After deletion: ");
    display(head);

    return 0;
}
