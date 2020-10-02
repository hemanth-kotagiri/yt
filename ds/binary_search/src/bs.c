#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

struct BNode {
    int value;
    struct BNode* left;
    struct BNode* right;
};

struct BNode* newNode(int value) {
    struct BNode* curr_node = (struct BNode*)malloc(sizeof(struct BNode));
    curr_node->value = value;
    curr_node->left = NULL;
    curr_node->right = NULL;

    return curr_node;
}

int binarySearchTree(struct BNode* curr, int v) {
    if (curr == NULL) {
        return false;
    }
    if (curr->value == v) {
        return true;
    }
    else if (curr->value > v) {
        return binarySearchTree(curr->left, v);
    }
    return binarySearchTree(curr->right, v);
}

int binarySearchList(int arr[], int v, int arr_length) {
    int L = 0;
    int R = arr_length - 1;

    while (L <= R) {
        int idx = L + floor((R - L) / 2);
        int value = arr[idx];
        if (value == v) {
            return idx;
        }
        else if (value > v) {
            R = idx - 1;
        }
        else {
            L = idx + 1;
        }
    }

    return -1;
}

int main() {

    struct BNode* head = newNode(10);
    
    // Left Sub Tree
    head->left = newNode(8);
    head->left->right = newNode(9);
    head->left->left = newNode(3);
    head->left->left->left = newNode(1);

    // Right Sub Tree
    head->right = newNode(12);
    head->right->left = newNode(11);
    head->right->right = newNode(15);
    head->right->right->left = newNode(14);
    head->right->right->left->left = newNode(13);


    printf("%d\n", binarySearchTree(head, 1));
    printf("%d\n", binarySearchTree(head, 13));
    printf("%d\n", binarySearchTree(head, 17));

    int list[7] = {1, 5, 7, 9, 11, 15, 17};
    printf("%d\n", binarySearchList(list, 1, 7));

    return 0;

}
