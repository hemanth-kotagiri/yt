#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

// Stack Implementation

struct Node* top = NULL;

void push(int value){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = value;
    new->next = top;
    top = new;
    printf("\nYayayayayayayayaya pushed!!!\n\n");
}


void pop(){
    if(top == NULL){
        return;
    }
    top = top->next;
    printf("DONE!\n");
}

void peek(){
    if(top == NULL){
        return;
    }

    printf("%d\n", top->data);

}

void showAllElements(){
    if(top == NULL) return;

    struct Node* temp;
    temp = top;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp -> next;
    }
    printf("\n");

}

//
// QUEUE implementation only.
//
// Should be pretty straight foward to understand
//

struct Queue {
    struct Node* head;
    struct Node* tail;
    size_t size;
};

struct Queue* create_queue() {
    struct Queue* list = (struct Queue*)malloc(sizeof(struct Queue));
    list->size = 0;
    list->head = list->tail = NULL;

    return list;
}

int queue_push(struct Queue* list, int data) {
    struct Node* item = (struct Node*)malloc(sizeof(struct Node));
    item->data = data;
    item->next = NULL;

    if (list->size == 0) {
        list->head = list->tail = item;
    }

    list->tail->next = item;
    list->tail = list->tail->next;
    return ++list->size;
}

int queue_pop(struct Queue* list) {
    if (list->size == 0) {
        return 0;
    }

    struct Node* head = list->head;
    list->head = list->head->next;
    --list->size;

    int val = head->data;
    free(head);
    return val;
}

int main() {
    // Testing the stack implementation

    int value, given;
    printf("1 => Push a value in Stack\n");
    printf("2 => Peek the top of the stack\n");
    printf("3 => Pop an element from Stack\n");
    printf("4 => Display all elements in Stack\n");
    printf("5 => Exit\n");

    do{
        printf(">>> ");
        scanf("%d", &given);

        switch(given){
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                push(value);
                break;
            
            case 2:
                peek();
                break;

            case 3:
                pop();
                break;
            
            case 4:
                showAllElements();

            case 5:
                break;
            
            default:
                printf("Not a valid input!");
        }
    }
    while(given!=5);

    return 0;
}

