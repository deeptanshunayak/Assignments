// Online C compiler to run C program online
#include <stdio.h>
#define max 10
typedef struct{
    int arr[max];
    int front;
    int rear;
} queue;

int isempty(queue *q){
    return q->front==q->rear;
}
void enqueue(queue *q,int data){
    if(isempty(q)){
        q->front=0;
        
    }
    q->arr[++q->rear]=data;
    
}
void dequeue(queue *q){
    if(isempty(q)){
        printf("queue is empty");
    }
    printf("the deleted element is;%d\n",q->arr[q->front]);
    q->front++;
}
int main() {
    
    queue q;
    q.front=-1;
    q.rear=-1;
    int n;
    printf("enter the no of elements:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        printf("enter the value:\n");
        scanf("%d",&data);
        enqueue(&q,data);
    }
    dequeue(&q);
    for(int i=q.front;i<=q.rear;i++){
        printf("%d ",q.arr[i]);
        
    }

    return 0;
}
