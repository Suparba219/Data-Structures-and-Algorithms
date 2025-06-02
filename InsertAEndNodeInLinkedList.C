#include<stdio.h>
#include<stdlib.h>
struct Node *createLinkedList(int arr[], int size);
void *INSERTNodeatending(struct Node *head, int data);
void *printlist(struct Node *head);
struct Node{
    int data;
    struct Node *next;
};

int main() {
   int arr[] = {10, 20, 30, 40, 50};
   struct Node *head;
   head = createLinkedList(arr,5);
   printlist(head);
   INSERTNodeatending(head,225);
}

void *INSERTNodeatending(struct Node *head, int data) {
   struct Node *current = head;
   while(current->next != NULL) {
    current = current->next;
   }
   struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
   temp->data = data;
   temp->next = NULL;
   current->next = temp;
   printlist(head);
}

void *printlist(struct Node *head) {
   struct Node *current = head;
   while(head != NULL) {
    printf("%d ->", head->data);
    head = head->next;
   }
   printf("NULL\n");
}

struct Node *createLinkedList(int arr[], int size) {
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int i;
   for(i = 0; i < size; i++) {
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
