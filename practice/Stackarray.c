#include <stdio.h>
#define max 10
typedef struct {
    int arr[max];
    int top;
}stack;

int isempty(stack *s){
    return s->top == -1;
}

int isfull(stack *s){
    return s->top == max-1;
}

void push(stack *s,int val){
    if(isfull(s)){
        printf("stack overflow");
        return;
    }
    s->arr[++s->top]=val;
}
int pop(stack *s){
    if(isempty(s)){
        printf("stack empty");
    }
    return s->arr[s->top--];
}
int peek(stack *s){
    if(isempty(s)){
        printf("stack empty");
    }
    return s->arr[s->top];
}
int main() {
    
    stack s;
    s.top=-1;
    int n;
    
    printf("enter the elements you want to push:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        printf("enter the value for %d:",i+1);
        scanf("%d",&data);
        push(&s,data);
    }
    printf("\n");
    for(int i=s.top;i>=0;i--){
        printf("%d ",s.arr[i]);
    }
    printf("the deleted element is:%d\n",pop(&s));
    printf("the top element is:%d\n",peek(&s));
    
    
    return 0;
}
