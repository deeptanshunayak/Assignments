#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

typedef struct queue{
    
    struct node *front;
    struct node *rear;
}queue;
struct node* CreateNode(int data);
int isEmpty(queue *q);
void pop(queue *q);
void push(queue *q,int data);
void display(queue *q);
int main()
{

    int n;
    queue q;
    q.front = NULL;  
    q.rear = NULL;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter the data for node %d:\n", i + 1);
        scanf("%d", &data);  // Add the missing '&'
        push(&q, data);
    }

    printf("queue elements:\n");
    display(&q);
     
    pop(&q);
}
struct node* CreateNode(int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (!new) {
        printf("Memory allocation failed\n");
        exit(1);  // Exit the program if malloc fails
    }
    new->data = data;
    new->next = NULL;

    return new;
}
int isEmpty(queue *q) {
    return q->front == NULL;
}
void push(queue *q,int data){
    
    struct node *new = CreateNode(data);
    if(q->front==NULL){
        q->front=new;
        q->rear=new;
    }
    q->rear->next = new;
    q->rear=new;
}
void pop(queue *q){
    
    if(isEmpty(q)){
        
       printf("queue is empty:"); 
    }
    printf("deleted element is :%d",q->front->data);
    struct node *temp=q->front;
    q->front = q->front->next;
    free(temp);
}
void display(queue *q) {
    if (isEmpty(q)) {
        printf("Stack is empty\n");
        return;
    }

    struct node *current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
