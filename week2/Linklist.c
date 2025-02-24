#include<stdio.h>
#include<stdlib.h>
struct Node *Createlist(int n);
void traverse(struct Node *head);
struct Node *Createnode(int data);
void InsertatBeginning(struct Node **head);
void InsertatEnding(struct Node **head);
struct Node{
    
    int data;
    struct Node* next;
    
};

int main()
{   int n;
    printf("enter the number of elements you want to enter:\n");
    scanf("%d",&n);
    
    struct Node *head = Createlist(n);
    if(head!=NULL){
        
        traverse(head);
    }
    InsertatBeginning(&head);
    printf("after insertion at beginning:\n");
     if(head!=NULL){
        
        traverse(head);
    }
    InsertatEnding(&head);
    printf("after insertion at end:\n");
     if(head!=NULL){
        
        traverse(head);
    }
    
    return 0;
}

struct Node *Createnode(int data){
    
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    
    if(!new){
        printf("allocation failed");
        return NULL;
    }
    
    new ->data = data;
    new ->next = NULL;
    
    return new;
    
}

struct Node *Createlist(int n){
    struct Node *head=NULL;
    struct Node *temp=NULL;
    if(n<=0){
        
        printf("enter valid node");
        return NULL;
    }
    for(int i=0;i<n;i++){
        
        int data;
        printf("enter the for node %d\n",i+1);
        scanf("%d",&data);
        
        struct Node *new = Createnode(data);
        
        if(head==NULL){
            
            head = new;
            
        }
        else{
            
            temp -> next = new;
        }
        
        temp=new;
    }
    return head;
}

void traverse(struct Node *head){
    
    struct Node *temp = head;
    while(temp!=NULL){
        
        printf("%d -- ",temp->data);
        temp=temp->next;
    }
}

void InsertatBeginning(struct Node **head){
    int data;
    printf("enter the node you want to insert:\n");
    scanf("%d",&data);
    struct Node *new = Createnode(data);
    if(new==NULL){
        printf("not valid");
    }
    
    new -> next=*head;
    *head = new;
    
}
void InsertatEnding(struct Node **head){
    
    int data;
    printf("enter the node you want to insert:\n");
    scanf("%d",&data);
    struct Node *new = Createnode(data);
    if(new==NULL){
        printf("not valid");
    }
    
    
    struct Node *temp = NULL;
    temp = *head;
    while(temp->next!=NULL){
        
        temp=temp->next;
    }
    
    temp->next = new;
    new -> next = NULL;
}
void InsertatSpecific(struct Node **head){
    
    int position;
    printf("enter the position you want to enter node\n:");
    scanf("%d",&position);
    
    if(position>1){
        
        printf("invalid position");
    }
    
    
    
    
}
