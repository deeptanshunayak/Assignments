#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct stack {
    struct node *head;  // Stack uses head as the top of the stack
} stack;

struct node* CreateNode(int data);
int isEmpty(stack *s);
void push(stack *s, int data);
void pop(stack *s);
int peek(stack *s);
void display(stack *s);

int main() {
    int n;
    stack s;
    s.head = NULL;  // Initialize the stack's head pointer to NULL

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter the data for node %d:\n", i + 1);
        scanf("%d", &data);  // Add the missing '&'
        push(&s, data);
    }

    printf("Stack elements:\n");
    display(&s);
     printf("top element of stack is %d",peek(&s));
    pop(&s);

    return 0;
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

int isEmpty(stack *s) {
    return s->head == NULL;
}

void push(stack *s, int data) {
    struct node *new = CreateNode(data);
    new->next = s->head;
    s->head = new;
}

void pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return;
    }
    printf("the deleted element is %d",s->head->data);
    struct node *temp = s->head;
    s->head = s->head->next;
    free(temp);
}

int peek(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;  // Return -1 to indicate the stack is empty
    }
    return s->head->data;
}

void display(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    struct node *current = s->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

