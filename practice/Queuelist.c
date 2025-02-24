// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
typedef struct Queue{
    node *front;
    node *rear;
}queue;
int isempty(queue *q){
    return q->front==NULL;
}
void enqueue(queue *q,int data){
    node *new = (node *)malloc(sizeof(node));
    if(isempty(q)){
        new -> data = data;
        new -> next = NULL;
        q->front = new;
        q->rear = new;
    }
    new -> data = data;
    new -> next = NULL;
    q->rear->next =new;
    q->rear = new;
}
void dequeue(queue *q){
    if(isempty(q)){
        printf("queue is empty");
        return;
    }
    node *temp = q->front;
    q->front = temp->next;
    free(temp);
}
void printqueue(queue *q){
    node *temp = q->front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main() {
    queue q;
    q.front = NULL;
    q.rear = NULL;
    
    int n;
    printf("enter no of elements:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        printf("enter the data:\n");
        scanf("%d",&data);
        enqueue(&q,data);
    }
    dequeue(&q);
    printqueue(&q);
    


    return 0;
}
