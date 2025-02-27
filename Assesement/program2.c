#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* Createlist(int n);
void traverse(struct Node* head);
struct Node* Createnode(int data);
void deleteAtPosition(struct Node** head, int position);

int main() {
    int n;
    printf("Enter the number of elements you want to enter:\n");
    scanf("%d", &n);

    struct Node* head = Createlist(n);
    if (head != NULL) {
        traverse(head);
    }

    printf("Enter the position you want to delete:\n");
    int position;
    scanf("%d", &position);
    if(position>0){
    deleteAtPosition(&head, position);}
    else{
	    printf("enter the valid position");
    }
    traverse(head);

    return 0;
}

struct Node* Createnode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (!newNode) {
        printf("Allocation failed\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* Createlist(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    if (n <= 0) {
        printf("Enter a valid number of nodes\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);

        struct Node* newNode = Createnode(data);

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }
    return head;
}

void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* del = temp->next;
    temp->next = temp->next->next;
    free(del);
}

