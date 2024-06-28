#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* arrayToLinkedList(int* array, int size) {
    if (size == 0) return NULL;

    Node* head = (Node*)malloc(sizeof(Node));
    if (!head) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    head->data = array[0];
    head->next = NULL;

    Node* current = head;
    for (int i = 1; i < size; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        newNode->data = array[i];
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeLinkedList(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);

    Node* linkedList = arrayToLinkedList(array, size);

    printf("Array: ");

    for (int i=0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Linked List: ");
    printLinkedList(linkedList);

    freeLinkedList(linkedList);

    return 0;
}
