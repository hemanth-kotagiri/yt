#include <stdlib.h>
#include <stdio.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

// Stack Implementation

struct StackNode* tail = NULL;

void stack_push(int value) {
    struct StackNode* new = (struct StackNode*)malloc(sizeof(struct StackNode));
    new->data = value;
    new->next = tail;
    tail = new;
}

int stack_pop() {
    if(tail == NULL) {
        return 0;
    }
    int popped_value = tail->data;
    tail = tail->next;
    printf("The value %d was popped!\n", popped_value);
    return popped_value;
}

void stack_peek() {
    if(tail == NULL) {
        return;
    }
    printf("%d\n", tail->data);
}

void stack_show_all_elements() {
    if(tail == NULL) return;

    struct StackNode* temp;
    temp = tail;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp -> next;
    }
    printf("\n");
}

void stack_prompt() {
    int value, given;
    printf("1 => Push a value in Stack\n");
    printf("2 => Peek the top of the stack\n");
    printf("3 => Pop an element from Stack\n");
    printf("4 => Display all elements in Stack\n");
    printf("5 => Exit\n");
    do {
        printf(">>> ");
        scanf("%d", &given);
        switch(given) {
            case 1: {
                printf("Value: ");
                scanf("%d", &value);
                stack_push(value);
                break;
            }
            case 2: {
                stack_peek();
                break;
            }
            case 3: {
                stack_pop();
                break;
            }
            case 4: {
                stack_show_all_elements();
            }
            case 5: {
                break;
            }
            default: {
                printf("Not a valid input!\n");
            }
        }
    } while(given!=5);
}

//
// QUEUE implementation only.
//
// Should be pretty straight foward to understand
//
struct Node {
    int data;
    struct Node* next;
};

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
    printf("The value %d was popped.\n", val);
    return val;
}

void queue_show_all_elements(struct Queue* list) {
    if (list->size == 0) {
        return;
    }
    struct Node* temp_pointer = list->head;
    while(temp_pointer != NULL) {
        printf("%d ", temp_pointer->data);
        temp_pointer = temp_pointer->next;
    }
    printf("\n");
}

void queue_prompt() {
    int value, given;
    printf("1 => Queue Push\n");
    printf("2 => Queue Pop\n");
    printf("3 => Show all Elements in Queue\n");
    printf("4 => Exit\n");
    // Creating our Queue
    struct Queue* our_queue = create_queue();
    do {
        printf(">>> ");
        scanf("%d", &given);
        switch(given) {
            case 1: {
                printf("Value: ");
                scanf("%d", &value);
                queue_push(our_queue, value);
                break;
            }
            case 2: {
                queue_pop(our_queue);
                break;
            }
            case 3: {
                queue_show_all_elements(our_queue);
            }
            case 4: {
                break;
            }
            default: {
                printf("Not a valid input!\n");
            }
        }
    } while(given!=4);

}

int main() {
    int choice;
    printf("Queue or Stack:(1/0): ");
    scanf("%d", &choice);
    if(choice == 1) {
        queue_prompt();
    }else if(choice == 0){
        stack_prompt();
    }
    return 0;
}

