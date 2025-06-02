#include<stdio.h>
#include<stdlib.h>
struct Node *createLinkedlist(int arr[], int size);
int INSERTNODEMiddleATLinkedlist(struct Node *head, int position, int data);
void *printLinkedlist(struct Node *head);
struct Node{
    int data;
    struct Node* next;
};

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    struct Node *head = NULL; 
    head = createLinkedlist(arr, 5);
    printLinkedlist(head);
    INSERTNODEMiddleATLinkedlist(head,3,225);
    printLinkedlist(head);
}

int INSERTNODEMiddleATLinkedlist(struct Node *head, int position, int data) {
    struct Node *temp = head;
    int counter = 0;
    while (temp != NULL) {
        counter++;
        if(counter == position) {
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp = temp->next;
    }
}

void *printLinkedlist(struct Node *head) {
     struct Node *temp = head;
     while(head != NULL) {
        printf("%d ->", head->data);
        head = head->next;
     }
     printf("NULL\n");
}

struct Node *createLinkedlist(int arr[], int size) {
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int i;
    for (i = 0; i < size; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        if(head == NULL) {
            head = temp;
            current = temp;
        }else{
            current->next = temp;
            current = current->next;
        }
    }
    return head;
}
