#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
    size_t size;
};

struct LinkedList* create_linked_list() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->size = 0;
    list->head = list->tail = NULL;

    return list;
}

int linked_list_push(struct LinkedList* list, int data) {
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

int linked_list_pop(struct LinkedList* list) {
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

