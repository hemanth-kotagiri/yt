#include <stdlib.h>

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
    return val;
}

int main() {
}

