// stack using linklisttypedef
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
typedef struct{
    node *top;
}stack;
int isempty(stack *s){
    return s->top==NULL;
}
void push(stack *s,int val){
    node *new = (node *)malloc(sizeof(node));
    if(!new){
        printf("stack overflow");
        return;
    }
    new -> data = val;
    new -> next = s->top;
    s->top = new;
}
int pop(stack *s){
    if(isempty(s)){
        printf("stack empty");
        return -1;
    }
    node *temp = s->top;
    int val = temp->data;
    s->top = temp -> next;
    free(temp);
    return val;
}
int peek(stack *s){
    if(isempty(s)){
        printf("stack empty");
    }
    return s->top->data;
}
int main() {
    stack s;
    s.top=NULL;
    int n;
    printf("enter the no of elemnts:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        printf("enter value for node %d\n",i+1);
        scanf("%d",&data);
        push(&s,data);    
        
    }
    printf("the popped value:%d\n",pop(&s));
    printf("the topelement is:%d\n",peek(&s));
    while(s.top!=NULL){
        printf("%d ",s.top->data);
        s.top=s.top->next;
    }
    

    return 0;
}
