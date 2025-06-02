#include<stdio.h>
#include<stdlib.h>
struct Node *createLinkedlist(int arr[], int size);
struct Node *delete(struct Node *head, int data);
void *printLinkedlist(struct Node *temp);
struct Node {
    int data;
    struct Node *next;
};

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    struct Node *head = NULL;
    head = createLinkedlist(arr, 5);
    printLinkedlist(head);
    struct Node *newhead = delete(head,30);
    printLinkedlist(head);
}

struct Node *delete(struct Node *head, int data) {
    struct Node *dummyhead = (struct Node *)malloc(sizeof(struct Node));
    dummyhead->next = head;
    struct Node *temp = dummyhead;
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            temp->next = temp->next->next;
        }else{
        temp = temp->next;
        }
    }
    return dummyhead->next;
}

void *printLinkedlist(struct Node *temp) {
   struct Node *head = temp;
   while(temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
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
