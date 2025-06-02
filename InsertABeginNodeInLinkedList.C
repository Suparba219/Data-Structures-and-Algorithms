#include<stdio.h>
#include<stdlib.h>
struct Node *createLinkedList(int arr[], int size);
int INSERTNodeatbeginning(struct Node *head, int data);
void *printlist(struct Node *temp);
struct Node{
    int data;
    struct Node *next;
};

int main() {
   int arr[] = {10, 20, 30, 40, 50};
   struct Node *head = NULL;
   head = createLinkedList(arr,5);
   printlist(head);
   INSERTNodeatbeginning(head,222);
}

int INSERTNodeatbeginning(struct Node *head, int data) {
   struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
   temp->data = data;
   temp->next = head;
   printlist(temp);
}

void *printlist(struct Node *temp) {
   struct Node *head = temp;
   while(temp != NULL) {
    printf("%d ->", temp->data);
    temp = temp->next;
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
