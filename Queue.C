#include<stdio.h>
#include<stdbool.h>

#define CAPACITY 5

int ourQueue[CAPACITY];
int front = 0, rear = -1, totalItem = 0;

bool isFull() {
    if(totalItem == CAPACITY) {
        return true;
    }else{
        return false;
    }
}

bool isEmpty() {
    if(totalItem == 0) {
        return true;
    }else{
        return false;
    }
}

void enqueue(int Item) {
      if(isFull()) {
        printf("Queue is full\n");
    
      }
      rear = (rear + 1) % CAPACITY;
      ourQueue[rear] = Item;
      totalItem++;
}

int dequeue() {
   if(isEmpty()) {
    printf("Sorry, Queue is empty\n");
    return 0;
   }
   int frontItem = ourQueue[front];
   ourQueue[front] = 0;
   front = (front + 1) % CAPACITY;
   totalItem--;
   return frontItem;
}

void printQueue() {
    int i;
    printf("Queue: ");
    for(i = 0; i < CAPACITY; i++) {
       printf("%d ", ourQueue[i]);
    }
    printf("\n");
}

int main() {
   enqueue(10);
   enqueue(20);
   enqueue(30);
   enqueue(40);
   printQueue();
   enqueue(50);
   printQueue();
   printf("Dequeue: %d\n", dequeue());
   printQueue();
   enqueue(60);
   printQueue();
}

