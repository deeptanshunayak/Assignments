

#include <stdio.h>
#include<stdlib.h>
struct Node* Createlist(int n);
void traverse(struct Node* head);
struct Node* Createnode(int data);
struct Node{
    
    int data;
    struct Node* next;
    
};

int main()
{   int n;
    printf("enter the number of elements you want to enter:\n");
    scanf("%d",&n);
    
    struct node *head = Createlist(n);
    if(head!=NULL){
        
        traverse(head);
    }
    return 0;
}

struct Node* Createnode(int data){
    
    struct Node* new = (struct node*)malloc(sizeof(struct Node));
    
    if(!new){
        printf("allocation failed");
        return NULL;
    }
    
    new ->data = data;
    new ->next = NULL;
    
    return new;
    
}

struct Node* Createlist(int n){
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
        
        struct Node* new = Createnode(data);
        
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
void traverse(struct Node* head){
    
    struct node *temp = head;
    while(temp!=NULL){
        
        printf("%d -- ",temp->data);
        temp=temp->next;
    }
}

#include <stdio.h>
#include<stdlib.h>
struct Node* Createlist(int n);
void traverse(struct Node* head);
struct Node* Createnode(int data);
struct Node{

	int data;
	struct Node* next;

};

int main()
{   int n;
	printf("enter the number of elements you want to enter:\n");
	scanf("%d",&n);

	struct node *head = Createlist(n);
	if(head!=NULL){

		traverse(head);
	}
	return 0;
}

struct Node* Createnode(int data){

	struct Node* new = (struct node*)malloc(sizeof(struct Node));

	if(!new){
		printf("allocation failed");
		return NULL;
	}

	new ->data = data;
	new ->next = NULL;

	return new;

}

struct Node* Createlist(int n){
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

		struct Node* new = Createnode(data);

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
void traverse(struct Node* head){

	struct node *temp = head;
	while(temp!=NULL){

		printf("%d -- ",temp->data);
		temp=temp->next;
	}
}

